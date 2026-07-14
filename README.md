# Lab 9 — Graph & Topological Sort

An edge-list `Graph` (read from a text file) and a `TopologicalSort` class that computes a valid ordering (via Kahn's algorithm / BFS with in-degree tracking) or reports that none exists because the graph has a cycle.

## Files

- `graph.h` — `Graph` (adjacency via edge list; `AddEdge`, `Adj`, `V`, `E`).
- `topological_sort.h` / `topological_sort.cc` — `TopologicalSort`, plus written answers to the graph-theory questions (Q1.1) as comments.
- `dag.txt` — sample acyclic graph (has a valid topological ordering).
- `cycle.txt` — sample graph containing a cycle (no valid ordering).

## Input format

First line is the vertex count `V`, followed by one `v w` edge per line.

## Build & run

```
g++ -std=c++17 -Wall -Wextra topological_sort.cc -o topsort
./topsort dag.txt
./topsort cycle.txt
```
