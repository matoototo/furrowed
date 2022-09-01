#pragma once

#include "board.hpp"
#include "constants.hpp"

int evaluate(const Board&);

const std::unordered_map<int, int> piece_value_map = {
    {PAWN_W, 100},
    {KNIGHT_W, 300},
    {BISHOP_W, 300},
    {ROOK_W, 500},
    {QUEEN_W, 900},
    {KING_W, 20000},
    {PAWN_B, -100},
    {KNIGHT_B, -300},
    {BISHOP_B, -300},
    {ROOK_B, -500},
    {QUEEN_B, -900},
    {KING_B, -20000},
    {BLANK, 0}
};


const std::unordered_map<int, std::vector<int>> placement_value_map = {
    {PAWN_W, {
        7,   7,   7,   7,   7,   7,   7,   7,   7,   7,
        7,   7,   7,   7,   7,   7,   7,   7,   7,   7,
        7, 500, 500, 500, 500, 500, 500, 500, 500,   7,
        7, 200, 200, 200, 200, 200, 200, 200, 200,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,  20,  20,   0,   0,   0,   7,
        7,   0,   0,   0,  20,  20,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   7,   7,   7,   7,   7,   7,   7,   7,   7,
        7,   7,   7,   7,   7,   7,   7,   7,   7,   7}},
    {KNIGHT_W, {
        7,   7,   7,   7,   7,   7,   7,   7,   7,   7,
        7,   7,   7,   7,   7,   7,   7,   7,   7,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   7,   7,   7,   7,   7,   7,   7,   7,   7,
        7,   7,   7,   7,   7,   7,   7,   7,   7,   7}},
    {BISHOP_W, {
        7,   7,   7,   7,   7,   7,   7,   7,   7,   7,
        7,   7,   7,   7,   7,   7,   7,   7,   7,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   7,   7,   7,   7,   7,   7,   7,   7,   7,
        7,   7,   7,   7,   7,   7,   7,   7,   7,   7}},
    {ROOK_W, {
        7,   7,   7,   7,   7,   7,   7,   7,   7,   7,
        7,   7,   7,   7,   7,   7,   7,   7,   7,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   7,   7,   7,   7,   7,   7,   7,   7,   7,
        7,   7,   7,   7,   7,   7,   7,   7,   7,   7}},
    {QUEEN_W, {
        7,   7,   7,   7,   7,   7,   7,   7,   7,   7,
        7,   7,   7,   7,   7,   7,   7,   7,   7,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   7,   7,   7,   7,   7,   7,   7,   7,   7,
        7,   7,   7,   7,   7,   7,   7,   7,   7,   7}},
    {KING_W, {
        7,   7,   7,   7,   7,   7,   7,   7,   7,   7,
        7,   7,   7,   7,   7,   7,   7,   7,   7,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,-100,-100,   0,   0,   0,   7,
        7,   0,   0,   0,-100,-100,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0, 100,   0,   0,   0, 100,   0,   7,
        7,   7,   7,   7,   7,   7,   7,   7,   7,   7,
        7,   7,   7,   7,   7,   7,   7,   7,   7,   7}},
    {PAWN_B, {
        7,   7,   7,   7,   7,   7,   7,   7,   7,   7,
        7,   7,   7,   7,   7,   7,   7,   7,   7,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0, -20, -20,   0,   0,   0,   7,
        7,   0,   0,   0, -20, -20,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,-200,-200,-200,-200,-200,-200,-200,-200,   7,
        7,-500,-500,-500,-500,-500,-500,-500,-500,   7,
        7,   7,   7,   7,   7,   7,   7,   7,   7,   7,
        7,   7,   7,   7,   7,   7,   7,   7,   7,   7}},
    {KNIGHT_B, {
        7,   7,   7,   7,   7,   7,   7,   7,   7,   7,
        7,   7,   7,   7,   7,   7,   7,   7,   7,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   7,   7,   7,   7,   7,   7,   7,   7,   7,
        7,   7,   7,   7,   7,   7,   7,   7,   7,   7}},
    {BISHOP_B, {
        7,   7,   7,   7,   7,   7,   7,   7,   7,   7,
        7,   7,   7,   7,   7,   7,   7,   7,   7,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   7,   7,   7,   7,   7,   7,   7,   7,   7,
        7,   7,   7,   7,   7,   7,   7,   7,   7,   7}},
    {ROOK_B, {
        7,   7,   7,   7,   7,   7,   7,   7,   7,   7,
        7,   7,   7,   7,   7,   7,   7,   7,   7,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   7,   7,   7,   7,   7,   7,   7,   7,   7,
        7,   7,   7,   7,   7,   7,   7,   7,   7,   7}},
    {QUEEN_B, {
        7,   7,   7,   7,   7,   7,   7,   7,   7,   7,
        7,   7,   7,   7,   7,   7,   7,   7,   7,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   7,   7,   7,   7,   7,   7,   7,   7,   7,
        7,   7,   7,   7,   7,   7,   7,   7,   7,   7}},
     {KING_B, {
        7,   7,   7,   7,   7,   7,   7,   7,   7,   7,
        7,   7,   7,   7,   7,   7,   7,   7,   7,   7,
        7,   0,   0,-100,   0,   0,   0,-100,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0, 100, 100,   0,   0,   0,   7,
        7,   0,   0,   0, 100, 100,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   0,   0,   0,   0,   0,   0,   0,   0,   7,
        7,   7,   7,   7,   7,   7,   7,   7,   7,   7,
        7,   7,   7,   7,   7,   7,   7,   7,   7,   7}},
};
