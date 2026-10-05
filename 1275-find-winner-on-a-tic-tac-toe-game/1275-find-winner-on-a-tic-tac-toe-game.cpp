class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        // AT END
        // {{{{if (moves.size() == 9)
        //     return "Draw";
        // else if (moves.size() < 5)
        //     return "Pending";
        // if(moves.size() == 5) return "A"; not this as it can have be pending
        // too}}}}}

        // start of code
        vector<vector<int>> board(3, vector<int>(3, 0));
        for (int i = 0; i < moves.size(); i++) {
            int r = moves[i][0];
            int c = moves[i][1];

            board[r][c] = (i % 2 == 0 ? 1 : 2); // 1 is for A and 2 is for B
        }
        // 0 means not placed any mark
        // 1 means X is there
        // 2 means O is there

        for (int i = 0; i < 3; i++) {
            if (board[i][0] != 0 && board[i][0] == board[i][1] &&
                board[i][1] == board[i][2])
                return board[i][0] == 1 ? "A" : "B";

            if (board[0][i] != 0 && board[0][i] == board[1][i] &&
                board[1][i] == board[2][i])
                return board[0][i] == 1 ? "A" : "B";
        }
        if (board[0][0] != 0 && board[0][0] == board[1][1] &&
            board[1][1] == board[2][2])
            return board[0][0] == 1 ? "A" : "B";

        if (board[0][2] != 0 && board[0][2] == board[1][1] &&
            board[1][1] == board[2][0])
            return board[0][2] == 1 ? "A" : "B";

        if (moves.size() == 9)
            return "Draw";
        return "Pending";
    }
};