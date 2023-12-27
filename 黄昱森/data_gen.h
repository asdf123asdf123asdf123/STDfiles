/*
数据生成器
v1.0.5-2
by 123asdf123
*/
#ifndef cpp_123asdf123_data_gen_H
#define cpp_123asdf123_data_gen_H
#ifndef cpp_123asdf123_graph_H
#include<bits/stdc++.h>
using namespace std;
#endif
#define CRT_SECURE_NO_WARNINGS
//fix 随机数一样 in v1.0.3
//fix namespace与class重名导致编译错误 in v1.0.5-2
random_device R;
mt19937 G(R());
namespace data_generator{
	class data_gen{
		public:
			//add in v1.0.0
			//构造生成器，同时输入指向的文件名 
			data_gen(string name){
				s=name;
				test=-1;
			}
			//打开文件 
			void open(string in_or_out){
				string t=s;
				if(test>=0)
					t+=to_string(test);
				string tmp=t+"."+in_or_out;
				freopen(tmp.c_str(),"wb",stdout);
			}
			//返回控制台 
			void close(){
				freopen("CON","wb",stdout);
			}
			//直接输出值 
			template<class T>void output(T v){
				cout<<v;
			}
			//返回随机整数(int/unsigned/short/unsigned short/long/unsigned long/long long/unsigned long long)
			template<class T>T random_int(T l,T r){
				return uniform_int_distribution<T>(l,r)(G);
			}
			//返回随机浮点数(float/double/long double)（需要手动强制(double)）
			template<class T>T random_double(T l,T r){
				return uniform_real_distribution<T>(l,r)(G);
			}
			//返回随机布尔值（可设定概率） 
			bool random_bool(double true_get_time=0.5){
				return bernoulli_distribution(true_get_time)(G);
			}
			//输出一个数组 
			template<class T>void output_array(T v[],int l,int r){
				for(int i=l;i<=r;i++)
					cout<<v[i];
			}
			//add in v1.0.1
			//假·endl
			void endl(){
				cout<<'\n';
			}
			//真·endl
			void endll(){
				cout<<std::endl;
			}
			//输出数组，两个值之间由一个值间隔 
			template<class T,class V>void output_array_between(T v[],int l,int r,V k){
				for(int i=l;i<r;i++)
					cout<<v[i]<<k;
				cout<<v[r];
			}
			//输出数组，两个值之间由一个数组的一段值循环间隔 
			template<class T,class V>void output_array_between_array(T v[],int l,int r,V k[],int between_start,int between_end){
				for(int i=l;i<r;i++)
					cout<<v[i]<<k[(i-l)%(between_end-between_start+1)+between_start];
				cout<<v[r];
			}
			//add in v1.0.2
			//直接输出一个随机整数(int/unsigned/short/unsigned short/long/unsigned long/long long/unsigned long long)
			template<class T>void output_random_int(T l,T r){
				cout<<uniform_int_distribution<T>(l,r)(G);
			}
			//直接输出一个随机浮点数(float/double/long double) （需要手动强制(double)）
			template<class T>void output_random_double(T l,T r){
				cout<<uniform_real_distribution<T>(l,r)(G);
			}
			//直接输出一个随机布尔值（可设定概率） 
			void output_random_bool(double true_get_time=0.5){
				cout<<bernoulli_distribution(true_get_time)(G);
			}
			//add in v1.0.3
			//构造函数可以同时输测试点编号了 
			data_gen(string name,int testcase){
				s=name;
				test=testcase;
			}
			//空格 
			void space(){
				cout<<" ";
			}
			//add in v1.0.4
			//连续输出同一个值 
			template<class T>void output(T v,int times){
				while(times--)
					cout<<v;
			}
			//连续输出同一个值，中间间隔一个值 
			template<class T,class V>void output(T v,int times,V between){
				times--;
				cout<<v;
				while(times--)
					cout<<between<<v;
			}
			//将整数数组[l,r]一段赋值为随机值 
			template<class T>void random_int_array(T v[],int l,int r,T min,T max){
				for(int i=l;i<=r;i++)
					v[i]=random_int(min,max);
			}
			//将浮点数数组[l,r]一段赋值为随机值 
			template<class T>void random_double_array(T v[],int l,int r,T min,T max){
				for(int i=l;i<=r;i++)
					v[i]=random_double(min,max);
			}
			//将布尔数组[l,r]一段赋值为随机值 
			void random_bool_array(bool v[],int l,int r,int true_get_time=0.5){
				for(int i=l;i<=r;i++)
					v[i]=random_bool(true_get_time);
			}
			//交换式对数组区间[l,r]随机排序 
			template<class T>void random_sort(T v[],int l,int r,int iteration=100000){
				while(iteration--)
					swap(v[random_int(l,r)],v[random_int(l,r)]);
			}
			//插入式对数组区间[l,r]随机排序 
			template<class T>void random_sort_insert(T v[],int l,int r){
				for(int i=l;i<r;i++)
					swap(v[i],v[random_int(i+1,r)]);
			}
			//add in v1.0.5
			//可以直接移至下一个测试点 
			void next_testcase(){
				try{
					if(test<0)
						throw("没有构建测试点！");
				}
				catch(const char* err){
					cerr<<err;
					exit(-1);
				}
				test++;
			}
			//支持重设生成器了 
			void reset(string name){
				s=name;
				test=-1;
			}
			//支持重设生成器了*2
			void reset(string name,int testcase){
				s=name;
				test=testcase;
			}
			//建图头文件，支持生成随机图 
			#ifdef cpp_123asdf123_graph_H
			#endif
		private:
			//add in v1.0.0
			string s;
			//add in v1.0.5
			int test;
	};
}
using namespace data_generator;
#endif
