#### <b>CS 121 Programming Assignment #2</b>

### Lance

February 2, 2023  
**Due:** February 10, 2023

  

# 1  Introduction

  

Program to read and dynamically allocate a multidimensional array in which a robot will randomly traverse. The program will take in the size of the grid, along with the max steps the robot is allowed to take. The program will terminate when either every point is visited, or when the robot has reached the max steps available and can take no more. Then, the program will output a grid showing how many times each point was visited, the amount of steps taken, and also each node that was visited the maximum amount of times, along with what that maximum value is.

  

- ## 1.1  Data Format

	-   A Grid class that stores all of the following data:
	    

	-   The two dimensional grid will be stored in a 2-D integer array.
	    
	-   Number of rows and columns, and the robots starting row and column will be stored as integers
	    
	-   The max steps available for the robot to take will be stored as an integer.
	    
	-   The maximum amount of times the robot can visit a grid will be stored as an integer.
	    

	-   There will also be four constant integers that will be global variables. These will hold: maximum grid size, minimum grid size, minimum position that the robot can access in the array, and the number of surrounding squares around the robot.
	    

  
  

- ## 1.2  Internal Data Structure
	
	-   Primary data structure will be the Grid class, that will store the dynamically allocated 2-D integer array that will act as the board. Each element in the 2-D array will hold the amount of times the robot has visited that unique point.
	    

	-   The class will also hold other relevant data like the grid size, max iterations, starting position of the robot, and maximum times the robot can visit each cell.
	    
	-   The class will also hold all of the necessary methods for the program to function.
	    
	-   An instance of the class will be used for the entire duration of the program.
	    

  
- ## 1.3  General Program Operation

	-   Read rows, columns, maximum iteration count, maxElementVisits, and the robot’s starting row and column.
	    
	-   Create an instance of the Grid class.
	    
	-   Dynamically allocate the 2-D array and initialize each element to 0.
	    
	-   Place the robot inside the 2-D array and increment that element’s count by one.
	    
	-   Loop the robot to traverse the grid until either of the three terminal cases are met: robot has traversed the entire grid, the robot has reached maximum number of iterations, or the robot is surrounded by cells that all have been visited the maximum number of times, and can no longer move.
	    
	-   Output the grid, the amount of steps taken, and any of the points where the robot reached the maximum threshold, along with outputting that threshold.
    

- ## 1.5  User-Defined Files to Create
	
	-   main.cpp – main file to house program data like grid data structure, as well as call the functions in correct order.
	    
	-   gridClass.cpp – houses the function definitions to functions that will be ran in main
	    
	-   gridClass.h – houses the prototype to the Grid class that's definitions are defined in gridClass.cpp.
    

## 1.4  Included Libraries
 - #### System Includes
	 - `<iostream>`
	 - `<random>`
	 - `<ctime>`
 - #### User-Defined Includes
	 - `“gridClass.h”`
    

  

# 2  Methods

- ## 2.1  Grid::Grid

	-  	**Purpose**: Dynamically allocate and initialize a two dimensional array that will act as the grid, and get input and initialize each necessary data member in the class
    
	-   **Arguments**: None
    
	-   **Return**: nothing
    

- ## 2.2  Grid::GetIntInput

	-   **Purpose**: Get integer input value from the user
	    

	-   **Arguments**: string to output that tells user what the value is, i.e “Enter row value: “.
	    
	-   **Return**: Integer value that was just inputted from user
    

- ## 2.3  Grid::PrintGrid

	-   **Purpose**: Print the entire 2-D grid array
	    
	-   **Arguments**: None
	    
	-   **Return**: Void
	    

- ## 2.4  Grid::PrintOutput

	-   **Purpose**: Print the necessary output at the end of the program
	    
	-   **Arguments**: integer that is the amount of times the robot looped through the array
	    
	-   **Return**: None
    

- ## 2.5  Grid::PrintMaxCells

	-   **Purpose**: Find out which points in the 2-D array have been visited the max amount of times by the robot, and then print out each of those points along with the number of max iterations allowed.
	    
	-   **Arguments**: None.
	    
	-   **Return**: Void
    

- ## 2.6  Grid::MoveRobot

	-   **Purpose**: Check to make sure the robot can move, and if it can then move the robot to one of the surrounding grids based on a 1/8th chance.
	    
	-   **Arguments**: Integer**& that is the reference to the grid, int& row and int& column that are the robots position, and two integers that are the grid size.
	    
	-   **Return**: Boolean to tell if the robot is not able to move out of its current position
    

- ## 2.7  Grid::CheckValidRobotMove

	-   **Purpose**: Check the position the robot wants to move is valid, i.e. that point on the grid exists (not a boundary location), that the point has not already been visited the max number of times allowed, and the move doesn’t leave the robot in the same position.
	    
	-   **Arguments**: Two integers row and column that are the desired position for the robot to move, and two integers that are the grid size.
	    
	-   **Return**: Integer that returns 0, 1, or 2 where 1 and 2 are error cases, and 0 is the non-error case.
    

- ## 2.8  Grid::StartMoving

	-   **Purpose**: Start moving the robot around the 2-D grid array until one of the three terminal cases are met: the robot has reached the max iterations, the robot is stuck, or the robot has visited each cell.
	    
	-   **Arguments**: None.
	    
	-   **Return**: integer that is the amount of iterations the robot took.
	    

- ## 2.9  Grid::CheckInput

	-   **Purpose**: Check to make sure the input from the user is valid, i.e. the row and columns are both greater than or equal to 1, the grid size is also >= 1x1, and also the grid size is <= 50x50, or that k>0.
	    
	-   **Arguments**: None.
	    
	-   **Return**: Void
	    

- ## 2.10  Grid::CheckEachCell

	-   **Purpose**: Loop through the entire 2-D grid array and check if each cell has been visited or not.
	    
	-   **Arguments**: None
	    
	-   **Return**: Boolean false if a cell hasn’t been visited, or true if all cells have been visited once
    

- ## 2.11  Grid::CheckSurroundingSquares

	-   **Purpose**: Check all of the surrounding squares of a cell if they have been visited the max number of times or not. This is used to tell if the robot is stuck with nowhere to go or not.
	    
	-   **Arguments**: None.
	    
	-   **Return**: Boolean true if each surrounding cell has been visited the max amount of times, false if not.