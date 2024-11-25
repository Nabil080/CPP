
import numpy as np
import subprocess
try:
	import matplotlib.pyplot as plt
except:
	subprocess.run("pip install matplotlib", shell=True)
	import matplotlib.pyplot as plt
import json

with open("config.json", "r") as fd:
	data = json.load(fd)
	name = data["name"]
	own_input = data["own_input"]
	point = data["point"]

def plot_triangle(vertices, x, y):
	# Ajouter le premier point à la fin pour fermer le triangle
	vertices = np.vstack((vertices, vertices[0]))

	plt.plot(vertices[:, 0], vertices[:, 1], 'bo-')
	plt.fill(vertices[:, 0], vertices[:, 1], alpha=0.3)

	plt.scatter(x, y, color='red', label='Point')

	plt.xlabel('Axe X')
	plt.ylabel('Axe Y')
	plt.title('Triangle en Python')
	plt.grid(True)
	plt.show()



def exec_coordonnees(point, x, y):
	# Construire la commande à exécuter
	commande = f"./{name} {point[0][0]} {point[0][1]} {point[1][0]} {point[1][1]} {point[2][0]} {point[2][1]} {x} {y}"
	print("Do 'make' and run :")
	print(commande)
	subprocess.run(commande, shell=True)
	# Spécifiez les coordonnées des sommets du triangle
	triangle_vertices = np.array(point)
	# Tracez le triangle
	plot_triangle(triangle_vertices, x, y)

if (own_input):
	point = []
	for i in range(1, 4):
		x = float(input(f"Point n°{i} du triangle, x -> "));
		y = float(input(f"Point n°{i} du triangle, y -> "));
		point.append([x, y]);
		pass;

	x = float(input(f"Point à évaluer, x -> "));
	y = float(input(f"Point à évaluer, y -> "));
	exec_coordonnees(point, x, y)
else:
	for i in range(len(point)):
		exec_coordonnees(point[i][0], point[i][1], point[i][2])



