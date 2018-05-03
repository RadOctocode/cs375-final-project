import random

def write_file(graph, path):
    with open('files/' + path, 'w+') as f:
        f.write(str(len(graph)) + '\n')
        for row in graph:
            for weight in row:
                f.write(str(weight) + ' ')
            f.write('\n')

#returns a list of lists of edges
def generate_graph(vertices):
    graph = [[0 for i in range(vertices)] for j in range(vertices)]
    for i in range(vertices):
        for j in range(i, vertices):
            weight = random.randint(1, 10)
            if j == i:
                graph[i][j] = 0
                continue
            graph[i][j] = weight
            graph[j][i] = weight
    return graph

def main():
    count_vert = input('enter number of vertices: ')
    path = input('enter file output path: ')
    graph = generate_graph(int(count_vert))
    write_file(graph, path)

main()
