import random

def write_file(graph, path):
    with open(path, 'w+') as f:
        f.write(str(len(graph)) + '\n')
        for i, k in enumerate(graph):
            f.write(str(i) + '\n')
            for v in k:
                f.write(str(v[0]) + ' ')
                f.write(str(v[1]) + ' ')
            f.write('\n')

#returns a list of lists of edges
def generate_graph(vertices):
    graph = [[] for i in range(vertices)]
    for i in range(vertices):
        for j in range(i, vertices):
            weight = random.randint(1, 10)
            if j == i:
                weight = 0
                graph[i].append((j, weight))
                continue
            graph[i].append((j, weight))
            graph[j].append((i, weight))
    # print(graph)
    return graph

def main():
    count_vert = input('enter number of vertices: ')
    path = input('enter file output path: ')
    graph = generate_graph(int(count_vert))
    write_file(graph, path)

main()
