#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
ordered_set<int> s;