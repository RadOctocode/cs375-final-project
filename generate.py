import random

def write_file(graph, path):
    with open(path, 'w+') as f:
        for i, k in enumerate(graph):
            f.write(str(i) + ' ' + str(len(k)) + ' ')
            f.write('\n')
            for edge in k:
                f.write(str(edge) + ' ')
            f.write('\n')

#returns a list of lists of edges
def generate_graph(vertices, density):
    graph = [[] for i in range(vertices)]
    for i in range(vertices):
        edge_count = random.randint(0, int(vertices**density)-1)
        if edge_count < 1: edge_count = 1
        for j in range(0, edge_count):
            edge = random.randint(0, vertices-1)
            # print(i)
            if edge not in graph[i]:
                graph[i].append(edge)
                graph[edge].append(i)
                # print(str(graph[i]) + ' ' + str(edge))
                # print(str(graph[edge]) + ' ' + str(i))
    # print(graph)
    return graph

def main():
    count_vert = input('enter number of vertices: ')
    density = input('enter density [0-1]: ')
    path = input('enter file output path: ')
    graph = generate_graph(int(count_vert), float(density))
    write_file(graph, path)

main()
