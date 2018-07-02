#include <iostream>
#include <iomanip>

using namespace std; 
int Mazewidth;
int Mazeheight;
cin Mazewidth ; 

char Maze [Mazeheight][Mazewidth] {
    "# #######",
    "#   #   #",
    "# ### # #",
    "# #   # #",
    "# # # ###",
    "#   # # #",
    "# ### # #",
    "#   #   #",
    "####### #",

};
const char Wall = "#";
const char Free = " ";
const char Mazerunner = "*" ; 
COORD StartingPoint(1, 0);
COORD EndingPoint(7, 8);

void PrintDaMaze()
{
    for (int Y = 0; Y < Mazeheight; Y++)
    {
        printf("%s\n", Maze[Y]);
    }
    printf("\n");
}

bool Solve(int X, int Y)
{
    // Make the move (if it's wrong, we will backtrack later.
    Maze[Y][X] = Mazerunner;

    
    PrintDaMaze();
    Sleep(50);

    // Check if we have reached our goal.
    if (X == EndingPoint.X && Y == EndingPoint.Y)
    {
        return true;
    }

    // Recursively search for our goal.
    if (X > 0 && Maze[Y][X - 1] == Free && Solve(X - 1, Y))
    {
        return true;
    }
    if (X < Mazewidth && Maze[Y][X + 1] == Free && Solve(X + 1, Y))
    {
        return true;
    }
    if (Y > 0 && Maze[Y - 1][X] == Free && Solve(X, Y - 1))
    {
        return true;
    }
    if (Y < Mazeheight && Maze[Y + 1][X] == Free && Solve(X, Y + 1))
    {
        return true;
    }

    // Otherwise we need to backtrack and find another solution.
    Maze[Y][X] = Free;

    // If you want progressive update, uncomment these lines...
    //PrintDaMaze();
    //Sleep(50);
    return false;
}

int _tmain(int argc, _TCHAR* argv[])
{
    if (Solve(StartingPoint.X, StartingPoint.Y))
    {
        PrintDaMaze();
    }
    else
    {
        printf("Damn\n");
    }

    return 0;
}
