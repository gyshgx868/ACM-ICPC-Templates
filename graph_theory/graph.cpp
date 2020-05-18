template <class T>
class Graph {
 public:
  int num_vertices;

  explicit Graph(int n) {
    num_vertices = n;
    head.resize(n, -1);
  }

  virtual void add_edge(int u, int v, T w = T()) {
    to.push_back(v);
    next.push_back(head[u]);
    weights.push_back(w);
    head[u] = to.size() - 1;
  }

  virtual void add_undirected_edge(int u, int v, T w = T()) {
    add_edge(u, v, w);
    add_edge(v, u, w);
  }

  virtual void add_flow_edge(int u, int v, T w = T()) {
    add_edge(u, v, w);
    add_edge(v, u, T());
  }

  int first_out_bound(int u) const { return head[u]; }

  int next_out_bound(int v) const { return next[v]; }

  int dest(int v) const { return to[v]; }

  T get_weight(int edge_index) const { return weights[edge_index]; }

  void set_weight(int edge_index, T w = T()) { weights[edge_index] = w; }

  int num_edges() const { return to.size(); }

 protected:
  std::vector<int> head;
  std::vector<int> to;
  std::vector<int> next;
  std::vector<T> weights;
};
