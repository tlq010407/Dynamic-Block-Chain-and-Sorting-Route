# Supply Chain Distribution and Transportation System

## Overview
This project is a C++ implementation of a **Supply Chain Distribution and Transportation System** that optimizes delivery routes to maximize efficiency and profit. It employs **three different routing algorithms**—Non-Optimized, Optimized, and Greedy—to determine the best delivery paths while considering cost-effectiveness and profit margins.

## Features
- **Route Optimization**: Implements different route selection strategies:
  - Non-Optimized Route
  - Optimized Route
  - Greedy Algorithm
- **Retailer Site Management**: Handles randomly generated retailer locations and their associated attributes (distance, order weight, cost, and profit).
- **Cost and Profit Calculation**: Computes fuel costs, wages, and profit margins for each route.
- **Interactive User Selection**: Allows users to choose a routing method and print the selected route to a file.
- **Performance Timing**: Measures execution time to analyze efficiency.

## Implementation Details
### 1. Retailer Site Data Generation
- Retailer sites are randomly generated with:
  - Name and location
  - X, Y coordinates
  - Order weight
  - Distance from origin
  - Cost-effectiveness score

### 2. Route Optimization Approaches
#### a) Non-Optimized Route
- Simply selects retailers that meet a minimum weight requirement.
- Does not prioritize shortest path or cost-effectiveness.

#### b) Optimized Route
- Selects retailers that meet a weight and distance requirement.
- Implements a **nearest neighbor heuristic** to minimize travel distance.

#### c) Greedy Algorithm
- Selects **8 retailers** based on cost-effectiveness.
- Can apply either a **Non-Optimized** or **Optimized** route strategy.

### 3. Cost and Profit Calculation
- **Total Cost** = (Fuel cost per km × Distance) + (Wage per hour × Driving time)
- **Profit Calculation**:
  - Selling price is assumed at 2 RM/kg.
  - Profit = Revenue - Delivery Cost.

### 4. User Interaction
- Users can select a route type and analyze:
  - Total Distance
  - Order Weight
  - Cost and Profit
- Users can **print the selected route** to a file (`RL_InitialRoute.txt`).

## File Structure
```
📂 Project Root
├── Main.cpp              # Main program logic
├── Generate.h            # Generates retailer data
├── RetailerSite.hpp      # Defines retailer site class
├── Cost_Effectiveness.h  # Handles cost and profit calculations
├── Comparison.h          # Compares route profitability
├── Display.h             # Displays results
├── Optimised.h           # Implements optimized route selection
├── Non-Optimised.h       # Implements non-optimized route selection
├── Greedy.h              # Implements greedy algorithm
├── Checking.h            # Validates user input
├── DeleteRetailers.h     # Removes retailers from route
├── RL_InitialRoute.txt   # Output file for selected routes
```

## How to Run
1. **Compile the Code**
   ```sh
   g++ -o SupplyChain Main.cpp
   ```
2. **Run the Program**
   ```sh
   ./SupplyChain
   ```
3. **Follow On-Screen Prompts** to select a route optimization method.

## Strengths and Weaknesses
### Strengths:
- Efficient cost-effectiveness comparison.
- Implements multiple routing strategies.
- Modular and well-structured C++ code.
- Allows user interaction and decision-making.

### Weaknesses:
- Simple nearest-neighbor heuristic (may not find truly optimal paths).
- Assumes static order weight and cost values.
- Limited real-world applicability without additional real-time data.

## Future Improvements
- Implement **Dijkstra’s Algorithm** for better path optimization.
- Add **real-time data handling** for dynamic order updates.
- Improve **scalability** for larger retailer networks.

## References
1. [Encapsulation in C++ (GeeksforGeeks)](https://www.geeksforgeeks.org/encapsulation-in-cpp/)
2. [Inheritance in C++ (GeeksforGeeks)](https://www.geeksforgeeks.org/inheritance-in-c/)

