# MovieSearchGame in C++
## OverView:
This C++ Word Search Game is designed to read a matrix of characters and a list of movies from a text file, then search for those movies in the matrix. The program displays the movies found along with their locations and directions within the matrix, as well as the list of movies that were not found.

## Features: 
Input from TXT file: The program takes input from a specified text file, extracting the matrix and movie list for the word search.
Matrix Search: Utilizes an efficient algorithm to search for movies in the matrix horizontally, vertically, and diagonally.
Detailed Output: Displays the movies found, their locations in the matrix, and the direction in which they were found. Additionally, lists the movies that were not found.

## Sample Output:
Matrix Size: 18 X 18 <br>
S C F R B O B R O B E R T S L O K L <br>
T N L E S R E K C I L S Y T I C R L <br>
A O E P O B L R U A E C H B U D E A <br>
R I T O T H E Y O M T O L B A T P H <br>
L T C M W R G I F M L B E E I B E E <br>
L C H A I B A O N I L L A U R G E I <br>
A E K N L U L D D G C I S L H K L N <br>
M L C T I L L A I N T A G O L H S N <br>
A E U D A L Y C U N Z H S Y L O S A <br>
C R R U R D B H S A G T E O P L U S <br>
L O T C L U L H L L B P C R A P L A <br>
U M S K I R O P O U L A L P E A A K <br>
E H N S A H N N S T L A S A C C E H <br>
L S O O R A D T E H S H B K C R O A <br>
E U O U F M E M E C O H E T H E E R <br>
S R M P A R T R B T A R O S A A S V <br>
S L E I S T O O T H E R U T L E S E <br>
N A T T A H N A M S E Y S L S S M Y <br>

Movies Found: <br>
ALLOFME found at coordinates 9, 5 <br>
ANNIEHALL found at coordinates 1, 18 <br>
BABE found at coordinates 3, 14 <br>
BEINGTHERE found at coordinates 3, 6 <br>
BIG found at coordinates 4, 14 <br>
BOBROBERTS found at coordinates 1, 5 <br>
BULLDURHAM found at coordinates 6, 6 <br>
CATBALLOU found at coordinates 2, 9 <br>
CITYSLICKERS found at coordinates 2, 5 <br>
CLERKS found at coordinates 3, 12 <br>
CLUELESS found at coordinates 10, 1 <br>
DUCKSOUP found at coordinates 9, 4 <br>
ELECTION found at coordinates 2, 2 <br>
FLETCH found at coordinates 1, 3 <br>
GHOSTBUSTERS found at coordinates 17, 5 <br>
HAPPYGILMORE found at coordinates 2, 7 <br>
HARVEY found at coordinates 18, 18 <br>
HOLIDAY found at coordinates 9, 7 <br>
LEGALLYBLONDE found at coordinates 3, 7 <br>
LIARLIAR found at coordinates 7, 5 <br>
LOCALHERO found at coordinates 17, 7 <br>
MALLRATS found at coordinates 1, 1 <br>
MANHATTAN found at coordinates 18, 1 <br>
MOONSTRUCK found at coordinates 7, 3 <br>
OHGOD found at coordinates 3, 5 <br>
PLAZASUITE found at coordinates 12, 8 <br>
REPOMAN found at coordinates 1, 4 <br>
RUSHMORE found at coordinates 9, 2 <br>
SLAPSHOT found at coordinates 16, 10 <br>
SLEEPER found at coordinates 2, 17 <br>
THERUTLES found at coordinates 17, 9 <br>
TOOTSIE found at coordinates 17, 3 <br>
TRADINGPLACES found at coordinates 4, 5 <br>
UNCLEBUCK found at coordinates 9, 9 <br>
YESMAN found at coordinates 18, 7 <br>
RUR found at coordinates 10, 3 <br>

Movies not found: <br>
CARS<br>
HOTSHOTS<br>
MEATBALLS<br>
NAPOLEANDYNAMITE<br>
RAISINGARIZONA<br>
SHREK<br>
SLACKER<br>
THEBELLBOY<br>
ZZZZZ<br>
