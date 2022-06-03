#include <iostream>
#include <vector>
using namespace std;
int n, m;
int t;
vector<int> truth;
vector<int> v[51];
int parent[51];

int find_parent(int p1) // 
{
  if (parent[p1] == p1)
  {
    return p1;
  }

  return parent[p1] = find_parent(parent[p1]);
}

void union_parent(int p1, int p2) // 
{

  int pp1 = find_parent(p1);
  int pp2 = find_parent(p2);

  if (pp1 < pp2)
  {
    parent[pp2] = pp1;
  }
  else
  {
    parent[pp1] = pp2;
  }
}
int main(void)
{
  scanf("%d%d", &n, &m);
  scanf("%d", &t);
  for (int i = 0; i < t; i++)
  {
    int tmp;
    scanf("%d", &tmp);
    truth.push_back(tmp);
  }

  for (int i = 1; i <= n; i++)
  {
    parent[i] = i;
  }

  for (int i = 0; i < m; i++)
  {
    int num;
    scanf("%d", &num);
    for (int j = 0; j < num; j++)
    {
      int tmp;
      scanf("%d", &tmp);
      v[i].push_back(tmp);
    }
  }

  for (int i = 0; i < m; i++)
  {
    int fir = v[i][0];
    for (int j = 1; j < v[i].size(); j++)
    {
      int next = v[i][j];
      union_parent(fir, next);
    }
  }
  int res = m;
  for (int i = 0; i < m; i++)
  {
    bool party = true;
    for (int j = 0; j < v[i].size(); j++)
    {

      if (!party)
        break;

      int cur = v[i][j];

      for (int k = 0; k < truth.size(); k++)
      {
        if (find_parent(cur) == find_parent(truth[k]))
        {
          party = false;
          break;
        }
      }
    }

    if (!party)
      res--;
  }

  printf("%d\n", res);
  return 0;
}