// #include "catch/catch_amalgamated.hpp"

// unsigned int Factorial( unsigned int number ) {
//     return number <= 1 ? number : Factorial(number-1)*number;
// }

// TEST_CASE( "Factorials are computed", "[factorial]" ) {
//     REQUIRE( Factorial(1) == 1 );
//     REQUIRE( Factorial(2) == 2 );
//     REQUIRE( Factorial(3) == 6 );
//     REQUIRE( Factorial(10) == 3628800 );
// }


//  TEST_CASE("Benchmarking-aiMove") {
// #if 0
//     BENCHMARK("Board-3") {
//         Game board(3);
//         board.addMove(1, 1, 'X');
//         aiMove(board);
//     };
//     BENCHMARK("Board-5") {
//         Game board(5);
//         board.addMove(1, 1, 'X');
//         aiMove(board);
//     };

//     BENCHMARK("Board-7") {
//         Game board(7);
//         board.addMove(1, 1, 'X');
//         aiMove(board);
//     };
// #endif
// }


// TEST_CASE("No-Winner-rand"){
//     Game g(3);
//     SECTION("Rand00"){

//         g.addMove(0,0, 'X');           // X - -
//         // g.addMove(0,1, 'X');        // - - -
//         // g.addMove(0,2, 'X');        // - - -
//         REQUIRE(g.Winner() == 0);
//     }
//     SECTION("Rand01"){
//         g.addMove(0,1, 'X');           // - X -
//         // g.addMove(0,1, 'X');        // - - -
//         // g.addMove(0,2, 'X');        // - - -
//         REQUIRE(g.Winner() == 0);
//     }

//     SECTION("Rand10"){
//         // g.addMove(0,0, 'X');         // - - -
//         g.addMove(1,0, 'X');            // X - -
//         //   g.addMove(0,2, 'X');        // - - -
//         REQUIRE(g.Winner() == 0);
//     }
//     SECTION("Rand11"){
//         // g.addMove(0,0, 'X');        // - - -
//         g.addMove(1,1, 'X');           // - X -
//         //   g.addMove(0,2, 'X');      // - - -
//         REQUIRE(g.Winner() == 0);
//     }

//     SECTION("Rand22"){
//         // g.addMove(0,0, 'X');        // - - -
//         g.addMove(2,2, 'X');          // - - -
//         //g.addMove(0,2, 'X');        // - - X
//         REQUIRE(g.Winner() == 0);
//     }

// }

// TEST_CASE("Winner3"){
//     Game g(3);
//     SECTION("Poziomy3X"){
//         g.addMove(0,0, 'X');        // X X X
//         g.addMove(0,1, 'X');        // - - -
//         g.addMove(0,2, 'X');        // - - -
//         REQUIRE(g.Winner() == 10);
//     }
//     SECTION("Poziomy3O"){
//         g.addMove(0,0, 'O');        // O O O
//         g.addMove(0,1, 'O');        // - - -
//         g.addMove(0,2, 'O');        // - - -
//         REQUIRE(g.Winner() == -10);
//     }

//     SECTION("Pionowy3"){
//         g.addMove(0,0, 'X');        // X - -
//         g.addMove(1,0, 'X');        // X - -
//         g.addMove(2,0, 'X');        // X - -
//         REQUIRE(g.Winner() == 10);
//     }
//     SECTION("Pionowy3O"){
//         g.addMove(0,0, 'O');        // O - -
//         g.addMove(1,0, 'O');        // O - -
//         g.addMove(2,0, 'O');        // O - -
//         REQUIRE(g.Winner() == -10);
//     }

//     SECTION("diagnonal3"){
//         g.addMove(0,0, 'X');        // X - -
//         g.addMove(1,1, 'X');        // - X -
//         g.addMove(2,2, 'X');        // - - X
//         REQUIRE(g.Winner() == 10);
//     }

//     SECTION("diagnonal3O"){
//         g.addMove(0,0, 'O');        // O - -
//         g.addMove(1,1, 'O');        // - O -
//         g.addMove(2,2, 'O');        // - - O
//         REQUIRE(g.Winner() == -10);
//     }

//     SECTION("rev-diagnonal3"){
//         g.addMove(0,2, 'X');            // - - X
//         g.addMove(1,1, 'X');            // - X -
//         g.addMove(2,0, 'X');            // X - -
//         REQUIRE(g.Winner() == 10);
//     }
//     SECTION("rev-diagnonal3O"){
//         g.addMove(0,2, 'O');            // - - O
//         g.addMove(1,1, 'O');            // - O -
//         g.addMove(2,0, 'O');            // O - -
//         REQUIRE(g.Winner() == -10);
//     }

// }

// TEST_CASE("Winner5"){
//     Game g(5);
//     SECTION("Poziomy5"){
//         g.addMove(2,0, 'X');        // - - - - -
//         g.addMove(2,1, 'X');        // - - - - -
//         g.addMove(2,2, 'X');        // X X X X X
//         g.addMove(2,3, 'X');        // - - - - -
//         g.addMove(2,4, 'X');        // - - - - -
//         REQUIRE(g.Winner() == 10);
//     }

//     SECTION("Pionowy5"){
//         g.addMove(2,0, 'X');        // - - X - -
//         g.addMove(2,1, 'X');        // - - X - -
//         g.addMove(2,2, 'X');        // - - X - -
//         g.addMove(2,3, 'X');        // - - X - -
//         g.addMove(2,4, 'X');        // - - X - -
//         REQUIRE(g.Winner() == 10);
//     }
//     SECTION("diagnonal5"){
//         g.addMove(0,0, 'X');        // X - - - -
//         g.addMove(1,1, 'X');        // - X - - -
//         g.addMove(2,2, 'X');        // - - X - -
//         g.addMove(3,3, 'X');        // - - - X -
//         g.addMove(4,4, 'X');        // - - - - X
//         REQUIRE(g.Winner() == 10);
//     }
//     SECTION("rev-diagnonal5"){
//         g.addMove(0,4, 'X');            // - - - - X
//         g.addMove(1,3, 'X');            // - - - X -
//         g.addMove(2,2, 'X');            // - - X - -
//         g.addMove(3,1, 'X');            // - X - - -
//         g.addMove(4,0, 'X');            // X - - - -
//         REQUIRE(g.Winner() == 10);
//     }
// }
// TEST_CASE("Game"){
//     Game g(3);
//     SECTION("IsMoveAllowed") {
//         g(1, 1) = 'x';
//         REQUIRE(g.isMoveAllowed(1, 1) == false);
//     }
//     SECTION("AddMove"){
//         g.addMove(1, 1, 'X');
//         REQUIRE(g(1, 1) == 'X');
//     }
//     SECTION("Fill/Clear"){
//         g(1,1) = 'X';
//         REQUIRE(g(0, 0) == '-');
//         g.clear();
//         REQUIRE(g(0, 0) == '-');
//     }
//     SECTION("AddSignToMatrix"){
//         g(1,1) = 'X';
//         REQUIRE(g(1, 1) == 'X');
//     }
// }