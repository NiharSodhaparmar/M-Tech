#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

class MerkleTree
{

private:
    vector<string> transactions;
    vector<string> tree;
    string hash(string message)
    {
        unsigned long long int hash = 0;
        for (char c : message)
        {
            int a = c;
            hash = hash*10 + a;
        }
        hash = hash % 99999;       
        return to_string(hash);
    }
    string combine_hashes(string hash1, string hash2)
    {
        return hash(to_string(stoi(hash1) + stoi(hash2)));
    }
    void build_tree_helper()
    {
        int j = tree.size() - 1;
        for(int i = transactions.size() - 1; i >=0; i--)
        {
            tree[j] = hash(transactions[i]);
            j--;
        }

        for(int i = (tree.size()/2) - 1; i >=0; i--)
        {
            if(tree[i] == "")
            {
                tree[i] = combine_hashes(tree[2*i + 1], tree[2*i + 2]);
            }
        }
        
       
    }

public:
    MerkleTree(vector<string> txns)
    {
        transactions = txns;
        tree.resize(txns.size(), "");
        build_tree_helper();
    }
    string get_root_hash()
    {
        return tree[0];
    }
};

int main()
{
    vector<string> txns = {"hell", "world", "how", "are", "you", "?"};
    MerkleTree tree(txns);
    cout << tree.get_root_hash();    
 
    return 0;
}
