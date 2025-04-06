import pygame
import itertools
import math
import random 
# Pygame setup
pygame.init()

# Constants
WIDTH, HEIGHT = 600, 600
FPS = 60
RADIUS = 5
LINE_WIDTH = 2  # Width of the path line

# Colors
WHITE = (255, 255, 255)
RED = (255, 0, 0)
BLUE = (0, 0, 255)
GREEN = (0, 255, 0)

# Initialize screen
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Traveling Salesman Problem")

# Function to calculate distance between two points
def distance(p1, p2):
    return math.sqrt((p2[0] - p1[0])**2 + (p2[1] - p1[1])**2)

# Brute-force approach to find the shortest path
def brute_force_tsp(distance_matrix):
    num_cities = len(distance_matrix)
    min_path = None
    min_distance = float('inf')

    # Generate all permutations of cities
    cities = list(range(num_cities))
    for perm in itertools.permutations(cities):
        dist = 0
        for i in range(len(perm) - 1):
            dist += distance_matrix[perm[i]][perm[i + 1]]
        dist += distance_matrix[perm[-1]][perm[0]]  # Return to the starting city

        if dist < min_distance:
            min_distance = dist
            min_path = perm

    return min_path

# Function to generate positions for cities on the screen (based on their index)
def generate_city_positions(count):
    positions = []
    for i in range(count):
        x = random.randint(50, WIDTH - 50)
        y = random.randint(50, HEIGHT - 50)
        positions.append((x, y))
    return positions

# Main function
def main():
    # Input distance matrix (example)
    distance_matrix = [
        [0, 10, 15, 20, 25],
        [10, 0, 35, 65, 30],
        [15, 35, 0, 90, 15],
        [200, 25, 0, 0, 50],
        [25, 10, 15, 5, 0]
    ]
    
    num_cities = len(distance_matrix)
    
    # Generate city positions for visualization
    city_positions = generate_city_positions(num_cities)

    # Calculate the shortest path using brute-force TSP
    shortest_path = brute_force_tsp(distance_matrix)

    # Pygame loop
    clock = pygame.time.Clock()
    running = True
    current_city = 0
    animation_speed = 0.5  # Delay for animation speed
    path_index = 1  # To track the current target in the shortest path

    while running:
        screen.fill(WHITE)

        # Draw the cities
        for i, pos in enumerate(city_positions):
            pygame.draw.circle(screen, RED, pos, 10)
            font = pygame.font.SysFont(None, 24)
            label = font.render(f"City {i+1}", True, (0, 0, 0))
            screen.blit(label, (pos[0] + 10, pos[1] - 10))

        # Draw the shortest path
        for i in range(len(shortest_path) - 1):
            pygame.draw.line(screen, BLUE, city_positions[shortest_path[i]], city_positions[shortest_path[i + 1]], LINE_WIDTH)
        pygame.draw.line(screen, BLUE, city_positions[shortest_path[-1]], city_positions[shortest_path[0]], LINE_WIDTH)

        # Animate the salesman's movement
        if path_index < len(shortest_path):
            pygame.draw.circle(screen, GREEN, city_positions[shortest_path[current_city]], RADIUS)

            # Move to the next city
            current_city = path_index
            path_index += 1

        # Event handling
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False

        pygame.display.update()
        clock.tick(FPS)

    pygame.quit()

if __name__ == "__main__":
    main()
