#include "ArcGraph.h"

ArcGraph::ArcGraph(int size) : vertices_count(size)
{
}

ArcGraph::ArcGraph(const IGraph& graph)
{
	vertices_count = graph.VerticesCount();
	for (int i = 0; i < graph.VerticesCount(); ++i)
	{
		for (int vert : graph.GetNextVertices(i))
		{
			adjacency_pairs.push_back({ i, vert });
		}
	}
}

ArcGraph::~ArcGraph()
{
}

void ArcGraph::AddEdge(int from, int to)
{
	adjacency_pairs.push_back({ from, to });
}

int ArcGraph::VerticesCount() const
{
	return vertices_count;
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const
{
	std::vector<int> next_vertices;
	for (std::pair<int, int> pair : adjacency_pairs)
	{
		if (pair.first == vertex)
		{
			next_vertices.push_back(pair.second);
		}
	}
	return next_vertices;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const
{
	std::vector<int> prev_vertices;
	for (std::pair<int, int> pair : adjacency_pairs)
	{
		if (pair.second == vertex)
		{
			prev_vertices.push_back(pair.first);
		}
	}
	return prev_vertices;
	return std::vector<int>();
}
