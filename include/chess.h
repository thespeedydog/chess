#pragma once
#include <cstring>
#include <string.h>
#include "helper.h"
#include "raylib/raylib.h"

Texture2D PawnTexture_w = LoadTexture("images/white_pawn.png");
Texture2D PawnTexture_b = LoadTexture("images/black_pawn.png");

Texture2D KnightTexture_w = LoadTexture("images/white_knight.png");
Texture2D KnightTexture_b = LoadTexture("images/black_knight.png");

Texture2D BishopTexture_w = LoadTexture("images/white_bishop.png");
Texture2D BishopTexture_b = LoadTexture("images/black_bishop.png");

Texture2D RookTexture_w = LoadTexture("images/white_rook.png");
Texture2D RookTexture_b = LoadTexture("images/black_rook.png");

Texture2D QueenTexture_w = LoadTexture("images/white_queen.png");
Texture2D QueenTexture_b = LoadTexture("images/black_queen.png");

Texture2D KingTexture_w = LoadTexture("images/white_king.png");
Texture2D KingTexture_b = LoadTexture("images/black_king.png");

typedef enum {
    // Normal
    UP = 8,
    DOWN = -8,
    LEFT = 1,
    RIGHT = -1,

    //Bishop
    B_UR = 7, // Up 1 Right 1
    B_UL = 9, // Up 1 Left 1r
    B_DL = -7,
    B_DR = -9,

    // Knight
    K_UR = 15,
    K_UL = 17,
    K_LU = 10,
    K_LD = -6,
    K_DL = -15,
    K_DR = -17,
    K_RD = -10,
    K_RU = 6
} MOVES;


void move(int shift, unsigned long long *location){
    if (shift < 0){
        *location >>= (-1 * shift);
    } else {
        *location <<= shift;
    }
}

typedef struct {
    unsigned long long location;
    unsigned long long *type_bitmap;

    Texture2D texture;
} Piece;


// White bitmaps
unsigned long long w_pawnBits;
unsigned long long w_knightBits;
unsigned long long w_bishopBits;
unsigned long long w_rookBits;
unsigned long long w_queenBits;
unsigned long long w_kingBits;

// Black bitmaps
unsigned long long b_pawnBits;
unsigned long long b_knightBits;
unsigned long long b_bishopBits;
unsigned long long b_rookBits;
unsigned long long b_queenBits;
unsigned long long b_kingBits;

unsigned int board;

// Pawns
Piece w_aPawn = {0, &w_pawnBits, PawnTexture_w};
Piece w_bPawn = {0, &w_pawnBits, PawnTexture_w};
Piece w_cPawn = {0, &w_pawnBits, PawnTexture_w};
Piece w_dPawn = {0, &w_pawnBits, PawnTexture_w};
Piece w_ePawn = {0, &w_pawnBits, PawnTexture_w};
Piece w_fPawn = {0, &w_pawnBits, PawnTexture_w};
Piece w_gPawn = {0, &w_pawnBits, PawnTexture_w};
Piece w_hPawn = {0, &w_pawnBits, PawnTexture_w};

Piece b_aPawn = {0, &b_pawnBits, PawnTexture_b};
Piece b_bPawn = {0, &b_pawnBits, PawnTexture_b};
Piece b_cPawn = {0, &b_pawnBits, PawnTexture_b};
Piece b_dPawn = {0, &b_pawnBits, PawnTexture_b};
Piece b_ePawn = {0, &b_pawnBits, PawnTexture_b};
Piece b_fPawn = {0, &b_pawnBits, PawnTexture_b};
Piece b_gPawn = {0, &b_pawnBits, PawnTexture_b};
Piece b_hPawn = {0, &b_pawnBits, PawnTexture_b};

// Bishops
Piece w_bishopQ = {0, &w_bishopBits, BishopTexture_w};
Piece w_bishopK = {0, &w_bishopBits, BishopTexture_w};

Piece b_bishopQ = {0, &b_bishopBits, BishopTexture_b};
Piece b_bishopK = {0, &b_bishopBits, BishopTexture_b};

// Knights
Piece w_knightQ = {0, &w_knightBits, KnightTexture_w};
Piece w_knightK = {0, &w_knightBits, KnightTexture_w};

Piece b_knightQ = {0, &b_knightBits, KnightTexture_b};
Piece b_knightK = {0, &b_knightBits, KnightTexture_b};

// Rooks
Piece w_rookQ = {0, &w_rookBits, RookTexture_w};
Piece w_rookK = {0, &w_rookBits, RookTexture_w};

Piece b_rookQ = {0, &b_rookBits, RookTexture_b};
Piece b_rookK = {0, &b_rookBits, RookTexture_b};

// Queens
Piece w_queen = {0, &w_queenBits, QueenTexture_w};
Piece b_queen = {0, &b_queenBits, QueenTexture_b};

// Kings
Piece w_king = {0, &w_kingBits, KingTexture_w};
Piece b_king = {0, &b_kingBits, KingTexture_b};



short file_to_number(char Char){
    switch (Char) {
        case 'a': return 1;
        case 'b': return 2;
        case 'c': return 3;
        case 'd': return 4;
        case 'e': return 5;
        case 'f': return 6;
        case 'g': return 7;
        case 'h': return 8;
    }
    return 0;
}

short number_to_file(int num){
    switch (num) {
        case 1: return 'a';
        case 2: return 'b';
        case 3: return 'c';
        case 4: return 'd';
        case 5: return 'e';
        case 6: return 'f';
        case 7: return 'g';
        case 8: return 'h';
    }
    return 0;
}

void play_move(char Move[], Piece* piece){
    *piece->type_bitmap ^= piece->location;

    short file_old = file_to_number(Move[0]);
    short rank_old =                Move[1];
    short file_new = file_to_number(Move[2]);
    short rank_new =                Move[4];

    int shift = ((file_new - file_old) * 8);
    if (shift > 0) shift -= (rank_new - rank_old);
    else           shift += (rank_new - rank_old);

    move(shift, &piece->location);

    *piece->type_bitmap |= piece->location;

    unsigned short move_size = Length(Move);
}

unsigned int setup_board(){
    unsigned int board = 0;
    Piece* wPawns[8] = {&w_aPawn,&w_bPawn,&w_cPawn,&w_dPawn,&w_ePawn,&w_fPawn,&w_gPawn,&w_hPawn};
    Piece* bPawns[8] = {&b_aPawn,&b_bPawn,&b_cPawn,&b_dPawn,&b_ePawn,&b_fPawn,&b_gPawn,&b_hPawn};


    char* move;
    char* buffer1;
    char* buffer2;

    unsigned short i = 0;
    // Pawns
    for (i = 1; i < 9; i++){
        // White Pieces
        *move = number_to_file(i);
        toString(buffer1, 2);
        strcat(move, buffer1);
        *buffer2 = *move;
        strcat(move, buffer2);

        play_move(move, wPawns[i-1]);

        // Black Pieces
        *move = number_to_file(i);
        toString(buffer1, 7);
        strcat(move, buffer1);
        *buffer2 = *move;
        strcat(move, buffer2);

        play_move(move, wPawns[i-1]);
    }

    // Setup Rooks
    play_move((char*)"a1a1", &w_rookQ);
    play_move((char*)"h1h1", &w_rookK);

    play_move((char*)"a8a8", &b_rookQ);
    play_move((char*)"h8h8", &b_rookK);

    // Setup Knights
    play_move((char*)"b1b1", &w_knightQ);
    play_move((char*)"g1g1", &w_knightK);

    play_move((char*)"b8b8", &b_knightQ);
    play_move((char*)"g8g8", &b_knightK);

    // Setup Bishops
    play_move((char*)"c1c1", &w_bishopQ);
    play_move((char*)"f1f1", &w_bishopK);

    play_move((char*)"c8c8", &b_bishopQ);
    play_move((char*)"f8f8", &b_bishopK);

    // Setup Queens
    play_move((char*)"d1d1", &w_queen);
    play_move((char*)"d8d8", &b_queen);

    // Setup Kings
    play_move((char*)"e1e1", &w_king);
    play_move((char*)"e8e8", &b_king);

    return board;
}
