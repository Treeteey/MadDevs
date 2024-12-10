/*
sudo apt-get install libsfml-dev
sudo apt -y install build-essential
*/


#pragma

#include <iostream>
#include <vector>
#include <unordered_set>
#include <random>
#include <algorithm>
#include <chrono>
#include <cmath>



class Point{
    public:
        double x_;
        double y_;
        std::vector<int> neighbours_;
        
        Point(double x, double y) : x_(x), y_(y) {}

        void print(){
            std::cout << x_ << " " << y_;
            std::cout << "  (";
            for(auto neighbor : neighbours_){
                std::cout << neighbor << " ";
            }
            std::cout << ")" << std::endl;
        }

        bool operator==(const Point& other) const {
            return x_ == other.x_ && y_ == other.y_;
        }

    private:


};



class Graph{
    public:        
        std::vector<Point> points_;
        int number_;
        double radius_;
        double price_;
        std::vector<std::vector<double>> distances_;

        Graph(){
            number_ = 100;
            radius_ = 1;
            price_ = 10;
            ClearDistances();  
            CreatePoints(radius_, number_);
            CreateNeighbours(2, 6);
        };

        Graph(int number, double radius, double price){
            number_ = number;
            radius_ = radius;            
            price_ = price;
            ClearDistances();  
            CreatePoints(radius_, number_);
            CreateNeighbours(2, 6);                 
        }

        void PrintGraph(){
            for(int i = 0; i < number_; ++i){
                std::cout << i << " ";
                points_[i].print();
            }
        }

    private:
        void ClearDistances(){
            distances_.resize(number_, std::vector<double>(number_));
            for(int i = 0; i < number_; i++){
                for(int j = 0; j < number_; j++){
                    distances_[i][j] = 0;
                }
            }
        }

        void CreatePoints(double radius, int count);
        double Distance(const Point& a, const Point& b);
        void CreateNeighbours(int min_neighbors, int max_neighbors);
};



std::vector<int> FindPathThroughAllPoints(Graph& g, int start);
double CalculatePathCost(const Graph& g, const std::vector<int>& path);
void PrintPath(const std::vector<int>& path, double cost);
void Run(Graph& g);
