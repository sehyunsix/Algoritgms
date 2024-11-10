			#include<iostream>
			#include<algorithm>
			#include<vector>
			#include<stack>
			// #define DEBUG
			using namespace std;


			bool visit_list[200001]={0,};
			bool is_sroop_list[200001]={0,};
			bool is_troop_list[200001]={0,};
			int order_list[200001]={0,};
			vector<int> edge_list[200001];
			int order =0;
			int level=0;


			bool dfs(int start, bool* is_roop_list) {
				stack<pair<int, int>> st;  // <노드, 자식 인덱스>
				st.push({start, 0});
				while (!st.empty()){

					auto [current, child_idx] = st.top();
					#ifdef DEBUG
					cout << "current : " << current << "child_idx : "<< child_idx<< endl;
					#endif


					if (order_list[current] == 0) {
						order++;
						order_list[current] = order;
					}

					// 현재 노드의 모든 자식을 처리했다면
					if (child_idx >= edge_list[current].size()) {

					for(int child: edge_list[current]){
						is_roop_list[current] |=  is_roop_list[child];
						}

					st.pop();
					visit_list[current] = false;
					order_list[current]=0;
					order--;


					}
					else{
						int next = edge_list[current][child_idx];

						if (is_roop_list[next]) {
							is_roop_list[current] = true;
							st.top().second++;
						}
						else if (!visit_list[next]) {
						visit_list[next] = true;

						#ifdef DEBUG
						cout << "push : " << next << endl;
						#endif

						st.top().second++;  // 부모의 다음 자식으로 이동

						st.push({next, 0});
						}
						else if (order_list[current] > order_list[next]) {

						#ifdef DEBUG
						cout << "push : " << next << endl;
						#endif

						st.top().second++;  // 부모의 다음 자식으로 이동
						st.push({next, 0});
						}
						else{

							st.top().second++;  // 부모의 다음 자식으로 이동

						}

					}
				}

				return true;
			}

			int main(){
			int N, M;
			cin >> N >> M;

			for(int i= 0; i<M; i++){

			int start ,end;
			cin >> start >> end;
			edge_list[start].push_back(end);

			}

			int S, T;
			cin >> S >> T;

			order=1;

			for(int i=0; i<200001; i++){
					order_list[i]=0;
					visit_list[i]=0;
					is_sroop_list[i]=0;
			}
			order_list[S]=1;
			is_sroop_list[S] =true;
			is_sroop_list[T] =true;
			dfs(S, is_sroop_list );

			#ifdef DEBUG
			cout <<"first dfs============="<<endl;
			#endif



			#ifdef DEBUG
			cout <<"second dfs============="<<endl;
			#endif

			for(int i=0; i<200001; i++){
					order_list[i]=0;
					visit_list[i]=0;
					is_troop_list[i]=0;
			}
			order=1;
			is_troop_list[T]=true;
			is_troop_list[S]=true;
			order_list[T]=1;
			dfs(T ,is_troop_list );



			int result =0;

			for(int i=0; i<200001; i++){
				if(i != S & i !=T){
				result += (is_sroop_list[i]&is_troop_list[i]);
				}
			}

			#ifdef DEBUG

			for(int i=0; i<20; i++){
				cout<< is_sroop_list[i] << " ";
			}
			cout << endl;
			for(int i=0; i<20; i++){
				cout<< is_troop_list[i] << " ";
			}
			cout << endl;

			for(int i=0; i<20; i++){
				cout<< visit_list[i] << " ";
			}
			cout << endl;

			for(int i=0; i<20; i++){
				cout<< visit_list[i] << " ";
			}
			cout << endl;
			#endif

			cout << result;


			}