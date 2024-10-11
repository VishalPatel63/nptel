// #include <bits/stdc++.h>
// #include <iostream>
// using namespace std;
// vector<int> friends;
// vector<int> ranks;
// vector<int>enemies;
// void Unionfind(int n)
// {
//     friends.resize(n);
//     ranks.resize(n);
//     enemies.resize(n,-1);
//     for (int i = 0; i < n; i++)
//     {
//         friends[i] = i;
//         ranks[i] = 0;
        
//     }
// }
// int find(int x)
// {
//     if (x == friends[x])
//     {
//         return x;
//     }
//     return friends[x] = find(friends[x]);
// }
// bool isSameSet(int x,int y){
//     return find(x) == find(y);
// }
// bool areFriends(int x,int y){
//     return (find(x) == find(y))? true: false;
// }

// bool areEnemies(int x,int y){
//        x = find(x);
//        y = find(y);

//     return (x == enemies[y] || y == enemies[x]) ? true: false;
// }
// void Union(int x, int y)
// {
//     int x_friends = find(x);
//     int y_friends = find(y);
//     if (x_friends == y_friends)
//     {
//         return;
//     }
//     if (ranks[x_friends] > ranks[y_friends])
//     {
//         friends[y_friends] = x_friends;
//     }
//     else if (ranks[x_friends] < ranks[y_friends])
//     {
//         friends[x_friends] = y_friends;
//     }
//     else
//     {
//         friends[x_friends] = y_friends;
//         ranks[y_friends]++;
//     }
// }


// int main()
// {
//     int n;
//     cin>>n;
//     int op,x,y;
//     int query = 0;
//     Unionfind(n);
//     while(cin>>op){
//        query++;
//        cin>>x>>y;

//        if(op == 1){
//         if(areEnemies(x,y)){
//             cout<<-1<<endl;
//         }
//         else{
//             x = find(x);
//             y = find(y);
//             //  case 1
//             if(enemies[x] == -1 && enemies[y] == -1){
//                 Union(x,y);
//             }

//             //   case 2
//             if(enemies[x] != -1 && enemies[y] == -1){
//                 int z = enemies[x];
//                 Union(x,y);
//                 x = find(x);
//                 enemies[z] = x;
//                 enemies[x] = z;
//             }

//             // case 3
//             if(enemies[x] == -1 && enemies[y] != -1){
//                 int z = enemies[y];
//                 Union(x,y);
//                 y = find(y);
//                 enemies[z] = y;
//                 enemies[y] = z;
//             }

//             // case 4
//             if(enemies[x] != -1 && enemies[y] != -1){
//                 int a = enemies[x];
//                 int b = enemies[y];
//                 Union(x,y);
//                 Union(a,b);
//                  a = find(a);
//                  x = find(x);
//                  enemies[x] = a;
//                  enemies[a] = x;
//             }
//         }
//        }

//       if(op == 2){
//         if(areFriends(x,y)){
//             cout<<-1<<endl;
//         }
//         else{
//             x = find(x);
//             y = find(y);
//             //  case 1
//             if(enemies[x] == y && enemies[y] == x){
//                 continue;
//             }

//             // case 2
//             if(enemies[x] == -1 && enemies[y] == -1){
//                 enemies[x] = y;
//                 enemies[y] = x;
//             }

//             // case 3
//             if(enemies[x] != -1 && enemies[y] == -1){
//                 int z = enemies[x];
//                 Union(z,y);
//                 int w = find(y);
//                 enemies[w] = x;
//                 enemies[x] = w;

//             }

//             // case 3
//             if(enemies[x] == -1 && enemies[y] != -1){
//                 int z = enemies[y];
//                 Union(z,x);
//                 int w = find(x);
//                 enemies[w] = y;
//                 enemies[y] = w;

//             }

//             // case 4
//              if(enemies[x] != -1 && enemies[y] != -1){
//                 int a = enemies[x];
//                 int b = enemies[y];
//                 Union(a,y);
//                 Union(b,x);
//                 int p = find(x);
//                 int q = find(y);
//                 enemies[p] = q;
//                 enemies[q] = p;
              

//             }
//         }
//       }

//       if(op == 3){
//         if(areFriends(x, y)){
//             cout<<1<<endl;
//         }
//         else{
//             cout<<0<<endl;
//         }
//       }

//       if(op == 4){
//         if(areFriends(x,y)){
//             cout<<1<<endl;
//         }
//         else{
//             cout<<0<<endl;
//         }
//       }

//     }
    
 
//     return 0;
// }




#include <bits/stdc++.h>
using namespace std;

vector<int> parent, ranks, enemy;

// Initialize Union-Find structure with n people
void UnionFind(int n) {
    parent.resize(n);
    ranks.resize(n);
    enemy.resize(n, -1);  // -1 means no enemy group set initially

    for (int i = 0; i < n; i++) {
        parent[i] = i;    // Each person is their own parent initially
        ranks[i] = 0;      // Rank is used for union by rank
    }
}

// Find the root representative of x with path compression
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

// Union two sets x and y, with union by rank
void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
        // Union by rank
        if (ranks[rootX] > ranks[rootY]) {
            parent[rootY] = rootX;
        } else if (ranks[rootX] < ranks[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            ranks[rootX]++;
        }
    }
}

// Set x and y as friends
bool setFriends(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX == rootY) return true; // They are already friends

    // If x and y are enemies, it's a contradiction
    if (enemy[rootX] == rootY) return false;

    // Union x and y
    unionSets(x, y);

    // Set the enemies' groups to be merged
    int enemyX = enemy[rootX];
    int enemyY = enemy[rootY];

    if (enemyX != -1 && enemyY != -1) {
        unionSets(enemyX, enemyY);  // Merge enemy groups
    } else if (enemyX != -1) {
        enemy[find(rootY)] = enemyX;
    } else if (enemyY != -1) {
        enemy[find(rootX)] = enemyY;
    }

    return true;
}

// Set x and y as enemies
bool setEnemies(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX == rootY) return false; // Contradiction: same group cannot be enemies

    // Set the enemies
    if (enemy[rootX] == -1) {
        enemy[rootX] = rootY;
    } else {
        unionSets(enemy[rootX], rootY);
    }

    if (enemy[rootY] == -1) {
        enemy[rootY] = rootX;
    } else {
        unionSets(enemy[rootY], rootX);
    }

    return true;
}

// Check if x and y are friends
bool areFriends(int x, int y) {
    return find(x) == find(y);
}

// Check if x and y are enemies
bool areEnemies(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    return (enemy[rootX] == rootY || enemy[rootY] == rootX);
}

int main() {
    int n;
    cin >> n;
    
    UnionFind(n); // Initialize the union-find structure

    while (true) {
        int c, x, y;
        cin >> c >> x >> y;

        if (c == 0 && x == 0 && y == 0) break;

        if (c == 1) {
            // Set x and y as friends
            if (!setFriends(x, y)) {
                cout << "-1\n"; // Contradiction
            }
        } else if (c == 2) {
            // Set x and y as enemies
            if (!setEnemies(x, y)) {
                cout << "-1\n"; // Contradiction
            }
        } else if (c == 3) {
            // Check if x and y are friends
            cout << areFriends(x, y) << '\n';
        } else if (c == 4) {
            // Check if x and y are enemies
            cout << areEnemies(x, y) << '\n';
        }
    }

    return 0;
}


