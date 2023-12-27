/*
����������
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
//fix �����һ�� in v1.0.3
//fix namespace��class�������±������ in v1.0.5-2
random_device R;
mt19937 G(R());
namespace data_generator{
	class data_gen{
		public:
			//add in v1.0.0
			//������������ͬʱ����ָ����ļ��� 
			data_gen(string name){
				s=name;
				test=-1;
			}
			//���ļ� 
			void open(string in_or_out){
				string t=s;
				if(test>=0)
					t+=to_string(test);
				string tmp=t+"."+in_or_out;
				freopen(tmp.c_str(),"wb",stdout);
			}
			//���ؿ���̨ 
			void close(){
				freopen("CON","wb",stdout);
			}
			//ֱ�����ֵ 
			template<class T>void output(T v){
				cout<<v;
			}
			//�����������(int/unsigned/short/unsigned short/long/unsigned long/long long/unsigned long long)
			template<class T>T random_int(T l,T r){
				return uniform_int_distribution<T>(l,r)(G);
			}
			//�������������(float/double/long double)����Ҫ�ֶ�ǿ��(double)��
			template<class T>T random_double(T l,T r){
				return uniform_real_distribution<T>(l,r)(G);
			}
			//�����������ֵ�����趨���ʣ� 
			bool random_bool(double true_get_time=0.5){
				return bernoulli_distribution(true_get_time)(G);
			}
			//���һ������ 
			template<class T>void output_array(T v[],int l,int r){
				for(int i=l;i<=r;i++)
					cout<<v[i];
			}
			//add in v1.0.1
			//�١�endl
			void endl(){
				cout<<'\n';
			}
			//�桤endl
			void endll(){
				cout<<std::endl;
			}
			//������飬����ֵ֮����һ��ֵ��� 
			template<class T,class V>void output_array_between(T v[],int l,int r,V k){
				for(int i=l;i<r;i++)
					cout<<v[i]<<k;
				cout<<v[r];
			}
			//������飬����ֵ֮����һ�������һ��ֵѭ����� 
			template<class T,class V>void output_array_between_array(T v[],int l,int r,V k[],int between_start,int between_end){
				for(int i=l;i<r;i++)
					cout<<v[i]<<k[(i-l)%(between_end-between_start+1)+between_start];
				cout<<v[r];
			}
			//add in v1.0.2
			//ֱ�����һ���������(int/unsigned/short/unsigned short/long/unsigned long/long long/unsigned long long)
			template<class T>void output_random_int(T l,T r){
				cout<<uniform_int_distribution<T>(l,r)(G);
			}
			//ֱ�����һ�����������(float/double/long double) ����Ҫ�ֶ�ǿ��(double)��
			template<class T>void output_random_double(T l,T r){
				cout<<uniform_real_distribution<T>(l,r)(G);
			}
			//ֱ�����һ���������ֵ�����趨���ʣ� 
			void output_random_bool(double true_get_time=0.5){
				cout<<bernoulli_distribution(true_get_time)(G);
			}
			//add in v1.0.3
			//���캯������ͬʱ����Ե����� 
			data_gen(string name,int testcase){
				s=name;
				test=testcase;
			}
			//�ո� 
			void space(){
				cout<<" ";
			}
			//add in v1.0.4
			//�������ͬһ��ֵ 
			template<class T>void output(T v,int times){
				while(times--)
					cout<<v;
			}
			//�������ͬһ��ֵ���м���һ��ֵ 
			template<class T,class V>void output(T v,int times,V between){
				times--;
				cout<<v;
				while(times--)
					cout<<between<<v;
			}
			//����������[l,r]һ�θ�ֵΪ���ֵ 
			template<class T>void random_int_array(T v[],int l,int r,T min,T max){
				for(int i=l;i<=r;i++)
					v[i]=random_int(min,max);
			}
			//������������[l,r]һ�θ�ֵΪ���ֵ 
			template<class T>void random_double_array(T v[],int l,int r,T min,T max){
				for(int i=l;i<=r;i++)
					v[i]=random_double(min,max);
			}
			//����������[l,r]һ�θ�ֵΪ���ֵ 
			void random_bool_array(bool v[],int l,int r,int true_get_time=0.5){
				for(int i=l;i<=r;i++)
					v[i]=random_bool(true_get_time);
			}
			//����ʽ����������[l,r]������� 
			template<class T>void random_sort(T v[],int l,int r,int iteration=100000){
				while(iteration--)
					swap(v[random_int(l,r)],v[random_int(l,r)]);
			}
			//����ʽ����������[l,r]������� 
			template<class T>void random_sort_insert(T v[],int l,int r){
				for(int i=l;i<r;i++)
					swap(v[i],v[random_int(i+1,r)]);
			}
			//add in v1.0.5
			//����ֱ��������һ�����Ե� 
			void next_testcase(){
				try{
					if(test<0)
						throw("û�й������Ե㣡");
				}
				catch(const char* err){
					cerr<<err;
					exit(-1);
				}
				test++;
			}
			//֧�������������� 
			void reset(string name){
				s=name;
				test=-1;
			}
			//֧��������������*2
			void reset(string name,int testcase){
				s=name;
				test=testcase;
			}
			//��ͼͷ�ļ���֧���������ͼ 
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
