
class Solution {
public:

    int find(int i, vector<int>& parent) {
        if(i == parent[i])
            return i;

        return parent[i] = find(parent[i], parent);
    }

    void un(int x, int y, vector<int>& parent, vector<int>& rank) {

        int x_p = find(x, parent);
        int y_p = find(y, parent);

        if(x_p == y_p)
            return;

        if(rank[x_p] > rank[y_p]) {
            parent[y_p] = x_p;
        }
        else if(rank[x_p] < rank[y_p]) {
            parent[x_p] = y_p;
        }
        else {
            parent[x_p] = y_p;
            rank[y_p]++;
        }
    }

    bool equationsPossible(vector<string>& equations) {

        int n = equations.size();

        vector<int> parent(26);
        vector<int> rank(26, 0);

        // Initially every character is its own parent
        for(int i = 0; i < 26; i++) {
            parent[i] = i;
        }

        // STEP 1: Process all == equations
        for(int i = 0; i < n; i++) {

            if(equations[i][1] == '=') {

                int x = equations[i][0] - 'a';
                int y = equations[i][3] - 'a';

                un(x, y, parent, rank);
            }
        }

        // STEP 2: Check all != equations
        for(int i = 0; i < n; i++) {

            if(equations[i][1] == '!') {

                int x = equations[i][0] - 'a';
                int y = equations[i][3] - 'a';

                int parent1 = find(x, parent);
                int parent2 = find(y, parent);

                if(parent1 == parent2)
                    return false;
            }
        }

        return true;
    }
};