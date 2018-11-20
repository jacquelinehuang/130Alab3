using std::cout;

struct node
{
  int perm;
  node *next;
};

Class Graph
{
 private:
    list <node> alist;

   public:
    Graph ();
    void addinGraph(int perm);
    void DFS ();

};
