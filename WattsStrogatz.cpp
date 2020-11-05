
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include<random>
#include <stdlib.h>
#include <algorithm>


//std::multiset<std::pair<int,int>> agraph;
std::vector<std::vector<int>> graph;

std::normal_distribution<double> aRandom(0.0, 1.0);
std::mt19937 gen (7);


#define Probability(p) (p>((rand()%10001)/100))


//=============================================================
void CreateRing (std::multiset<std::pair<int,int>> &graph
                 , int N
                 , int V) {

   graph.clear();

   for (int i = 0; i < N; i++) {
      for (int j = i+1; j <= i+V; j++) {

         int k = (j + N) % N;
 
         graph.insert (std::make_pair(i,k));
      }
   }
}


//=============================================================
void WattsStrogatz (std::vector<std::vector<int>> &graph
                    , int N
                    , int V
                    , int beta) {

   int k2;

   graph.clear();

   std::vector<int> w;

   // for each vertex,
   for (int i = 0; i < N; i++) {

      // initially there's no link.
      w.clear();

      // how many links we'll create?
      int q = V + aRandom(gen);

      q = (q < 1) ? i+1 : i+q;

      for (int j = i+1; j <= q; j++) {

         // default destination vertice, for a regular ring.
         int k = (j + N) % N;
 
         // but with a little luck, replace 'k' with another destination
         if (Probability(beta)) {

            // how many options do we have?
            int n = N - 1 - V;  // answer: not self-link, not neighbors that form a ring.

            // try twice to create a random link that does not exist already.
            int t,z;
            for (z = 0; z < 2; z++) {
               t  = rand() % n;
               k2 = (i + V + 1 + t) % N;
               
               //check if already exists
               if (w.end() != find(w.begin(), w.end(), k2)) continue;

               // must check in the reverse direction also!
               if (k2 < i)
                  if (graph[k2].end() != find(graph[k2].begin(), graph[k2].end(), i)) continue;
           }

           // ok, that worked; we got a random link
           if (z < 2) 
              k = k2;
         }
         // insert destination in the list
         w.push_back(k);
      }
      // and insert list of vertices into the graph.
      graph.push_back(w);
   }
}

//-----------------------------------
void complete_graph () {

   std::vector<std::vector<int>> aux;

   aux = graph;
   
   int k = 0;

   for (auto a:aux) {

      for (auto b:a)
         graph[b].push_back(k);

      ++k;
   }
}

//=========================================================
int main () {


   WattsStrogatz (graph, 9, 4, 30);

   int k = 0;

   puts ("First option, each vertex has a list of exit links:");

   for (auto a:graph) {
      printf ("\n %d => ", k++);
      for (auto b:a)
         printf (" %d", b);
   }


   puts ("----------------------\nSecond option, each vertex has a list of all links: ");

   complete_graph();

   k = 0;

   for (auto a:graph) {
      printf ("\n %d => ", k++);
      for (auto b:a)
         printf (" %d", b);
   }

   puts ("\n----------------------");

  return 0;
}
