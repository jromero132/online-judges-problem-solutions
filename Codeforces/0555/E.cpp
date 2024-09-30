// Problem name: Case of Computer Network
// Problem link: https://codeforces.com/contest/555/problem/E
// Submission link: https://codeforces.com/contest/555/submission/98408619

#include <iostream>
#include <set>
#include <vector>

#define pb push_back

using namespace std;

typedef pair<int, int> pii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;

void dfs_discovery_time(vvi &graph, int node, int parent, int &time, vi &discovery_time, vi &highest_reachable_time, set<pii> &bridges){
    discovery_time[ node ] = highest_reachable_time[ node ] = time++;
    bool parent_already_visited = false;
    for(int child : graph[ node ]){
        if(!discovery_time[ child ]){ // unvisited node
            dfs_discovery_time(graph, child, node, time, discovery_time, highest_reachable_time, bridges);
            if(highest_reachable_time[ child ] == discovery_time[ child ]) // (node <-> child) edge is a bridge
                bridges.insert(make_pair(min(node, child), max(node, child)));
        }
        if(parent != child || parent_already_visited)
            highest_reachable_time[ node ] = min(highest_reachable_time[ node ], highest_reachable_time[ child ]); // trying to update highest reachable time
        else
            parent_already_visited = true;
    }
}

void set_bicconected_component(vvi &graph, int node, vi &biconnected_component, set<pii> &bridges, vvi &compressed_graph){
    for(int child : graph[ node ])
        if(!biconnected_component[ child ]){ // unvisited node
            if(bridges.find(make_pair(min(node, child), max(node, child))) == bridges.end()) // if not a bridge edge
                biconnected_component[ child ] = biconnected_component[ node ];
            else{ // new biconnected component
                biconnected_component[ child ] = compressed_graph.size();
                compressed_graph.pb(vi(0));
                compressed_graph[ biconnected_component[ node ] ].pb(biconnected_component[ child ]); // edge from component
                compressed_graph[ biconnected_component[ child ] ].pb(biconnected_component[ node ]); // edge from component
            }
            set_bicconected_component(graph, child, biconnected_component, bridges, compressed_graph);
        }
}

void set_height_and_parent(vvi &graph, int node, vi &height, vvi &parent){
    for(int child : graph[ node ])
        if(!height[ child ]){ // unvisited node
            parent[ child ].pb(node);
            height[ child ] = height[ node ] + 1;
            set_height_and_parent(graph, child, height, parent);
        }
}

void build_lca(vvi &parent){
    parent[ 0 ] = vi(1, 0);
    for(int dist = 1 ; (1 << dist) < parent.size() ; ++dist){
        parent[ 0 ].pb(0);
        for(int i = 1 ; i < parent.size() ; ++i)
            parent[ i ].pb(parent[ parent[ i ][ dist - 1 ] ][ dist - 1 ]); // parent of i at distance (2 ^ dist) is parent at distance (2 ^ (dist - 1)) of parent at distance (2 ^ (dist - 1)) of i
    }
}

int get_lca(vvi &parent, vi &height, int v, int u){
    if(height[ v ] < height[ u ])
        swap(v, u);

    int diff = height[ v ] - height[ u ];
    for(int bit = 0 ; diff ; ++bit)
        if((1 << bit) & diff)
            diff ^= (1 << bit), v = parent[ v ][ bit ]; // making both nodes at the same height

    if(v == u) // lca already found
        return v;

    for(int i = parent[ v ].size() ; i-- ; )
        if(parent[ v ][ i ] != parent[ u ][ i ]) // highest different parent
            v = parent[ v ][ i ], u = parent[ u ][ i ];

    return parent[ v ][ 0 ] == parent[ u ][ 0 ] ? parent[ v ][ 0 ] : 0; // finding possible lca or nothing
}

void update_dp(vvi &graph, int node, vvi &dp, vb &visited){
    visited[ node ] = true;
    for(auto child : graph[ node ])
        if(!visited[ child ]){
            update_dp(graph, child, dp, visited);
            for(int i = dp[ node ].size() ; i-- ; )
                dp[ node ][ i ] += dp[ child ][ i ];
        }
}

int main()
{
    // faster stdin read
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // nodes, channels and important messages
    int n, m, q;
    cin >> n >> m >> q, ++n;

    // reading channels and storing them as a graph
    vvi graph(n);
    for(int v, u ; m-- ; ){
        cin >> v >> u;
        graph[ v ].pb(u);
        graph[ u ].pb(v);
    }

    int time = 1;
    vi discovery_time(n), highest_reachable_time(n);
    set<pii> bridges;
    for(int i = 1 ; i < n ; ++i)
        if(!discovery_time[ i ])
            dfs_discovery_time(graph, i, 0, time, discovery_time, highest_reachable_time, bridges); // setting discovery time

    vi biconnected_component(n);
    vvi compressed_graph(1);
    for(int i = 1 ; i < n ; ++i)
        if(!biconnected_component[ i ]){
            biconnected_component[ i ] = compressed_graph.size();
            compressed_graph.pb(vi(0));
            set_bicconected_component(graph, i, biconnected_component, bridges, compressed_graph); // compressing graph
        }

    int biconnected_components = compressed_graph.size();
    vi height(biconnected_components);
    vvi parent(biconnected_components);
    for(int i = 1 ; i < biconnected_components ; ++i)
        if(!height[ i ]){
            height[ i ] = 1;
            parent[ i ].pb(0);
            set_height_and_parent(compressed_graph, i, height, parent); // hanging the tree and calculating nodes height
        }

    build_lca(parent); // building LCA pre-calculated table

    vvi dp(biconnected_components, vi(3, 0));
    // dp[ X ][ 0 ] => number of nodes in X subtree that are beginnings of queries' paths
    // dp[ X ][ 1 ] => number of nodes in X subtree that are ends of queries' paths
    // dp[ X ][ 2 ] => number of times X is LCA of a query
    for(int v, u ; q-- ; ){
        cin >> v >> u;
        v = biconnected_component[ v ], u = biconnected_component[ u ];

        if(v == u) // if both are in the same biconnected component => it's a valid query (set edges direction in dfs direction for every biconnected component)
            continue;

        int lca = get_lca(parent, height, v, u);
        if(!lca){ // no LCA between both nodes => no answer
            cout << "No" << endl;
            return 0;
        }
        else{
            ++dp[ v ][ 0 ];
            ++dp[ u ][ 1 ];
            ++dp[ lca ][ 2 ];
        }
    }

    vb visited(biconnected_components);
    for(int i = 1 ; i < biconnected_components ; ++i){
        if(!visited[ i ])
            update_dp(compressed_graph, i, dp, visited);

        if(dp[ i ][ 0 ] > dp[ i ][ 2 ] && dp[ i ][ 1 ] > dp[ i ][ 2 ]){ // if both, number of beginning and end queries are greater than number of times this node is LCA of a query path => no answer
            // if number of beginning query path is greater than number of times this node is LCA of a query path => edge direction is from this node to its parent
            // if number of end query path is greater than number of times this node is LCA of a query path => edge direction is from the parent of this node to this node
            // if both, number of beginning and end queries are equal to the number of times this node is LCA of a query path => any direction for edge from this node to its parent
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}