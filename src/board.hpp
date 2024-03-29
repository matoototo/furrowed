#pragma once

#include <vector>
#include <string>
#include <cstdint>
#include <unordered_set>

#include "move.hpp"
#include "table.hpp"

inline int captures = 0;
inline int en_passants = 0;
inline int castles = 0;
inline int promotions = 0;

bool is_capture(const Board& board, const Move& move);

struct Board {
    Board() {
        reset_board();
    }
    Board(const std::string& FEN) {
        set_FEN(FEN);
    }

    void reset_board();
    void set_FEN(const std::string&);
    void print_board() const;
    void make_move(const Move&, bool count = false, Table* table_ptr = nullptr);
    void generate_hash(const Table& t) {
        hash = t.zobrist_hash(*this);
    }
    std::vector<Move> legal_moves() const;
    std::vector<Move> pseudo_legal_moves() const;
    std::vector<Move> forcing_moves() const;
    bool is_in_check(const int) const;
    int find_king(bool flip = false) const;
    std::string to_fen() const;

    std::vector<int> board;
    bool is_white;
    bool castle_K;
    bool castle_Q;
    bool castle_k;
    bool castle_q;
    int en_passant;
    unsigned long long hash;
    uint fifty_move;
    int ply_number;
    mutable int piece_value = 1e9;
    mutable int placement_value = 1e9;

    bool operator==(const Board& other) const {
        return (
            board == other.board &&
            is_white == other.is_white &&
            castle_K == other.castle_K &&
            castle_Q == other.castle_Q &&
            castle_k == other.castle_k &&
            castle_q == other.castle_q &&
            en_passant == other.en_passant &&
            fifty_move == other.fifty_move &&
            ply_number == other.ply_number
        );
    };

    private:
    void add_moves(std::vector<Move>&, const std::vector<int>&, const int, bool, int) const;
    void add_attackers(std::vector<int>&, const int) const;
    void add_promotions(std::vector<Move>&, const int, const int) const;
    void add_pawn_moves(std::vector<Move>&, const int) const;
    void add_knight_moves(std::vector<Move>&, const int) const;
    void add_bishop_moves(std::vector<Move>&, const int) const;
    void add_rook_moves(std::vector<Move>&, const int) const;
    void add_queen_moves(std::vector<Move>&, const int) const;
    void add_king_moves(std::vector<Move>&, const int) const;
    bool move_is_legal(const Move&, int) const;
    bool move_is_forcing(const Move&, int) const;
};
