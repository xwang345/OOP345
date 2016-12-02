#pragma once
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <math.h>

namespace w8
{
	template<typename T>
	class DataTable
	{
		std::vector<T> xvalues;
		std::vector<T> yvalues;
		int width;
		int decimals;
	public:
		DataTable(std::ifstream& fs, const int fw, const int nd)
		{			

			width = fw;
			decimals = nd;

			T x, y;
			while (fs.good()){
				fs >> x >> y;
				xvalues.push_back(x);
				yvalues.push_back(y);
			}			
		}
		~DataTable() 
		{
			xvalues.clear();
			yvalues.clear();
		};

		T mean() const
		{
			T yTot = std::accumulate(yvalues.begin(), yvalues.end(), 0.0f);
			return yTot / yvalues.size();
		}
		T sigma() const
		{
			T meanValue = mean();
			T sum = 0.0;
			for (size_t i = 0; i < yvalues.size(); i++){
				sum += (yvalues[i] - meanValue)*(yvalues[i] - meanValue);
			}
			return sqrt(sum / (yvalues.size() - 1));

		}

		T median() const
		{
			std::vector<T> temp = yvalues;
			std::sort(temp.begin(), temp.end());
			return temp[temp.size() / 2];
		}

		void regression(T& slope, T& y_intercept) const
		{
			T avgX = std::accumulate(xvalues.begin(), xvalues.end(), 0.0f) / xvalues.size();
			T avgY = std::accumulate(yvalues.begin(), yvalues.end(), 0.0f) / yvalues.size();

			// numerator and denominator of slope
			T numer = 0.0, denom = 0.0;
			for (size_t i = 0; i < xvalues.size(); ++i)
			{
				numer += (xvalues[i] - avgX) * (yvalues[i] - avgY);
				denom += (xvalues[i] - avgX) * (xvalues[i] - avgX);
			}

			slope = numer / denom;
			y_intercept = avgY - (slope * avgX);	// y=mx+b --> b=y-(mx);

		}
		void display(std::ostream& os) const
		{
			os << std::setw(width) << "x"
				<< std::setw(width) << "y" << std::endl;

			for (size_t i = 0; i < xvalues.size(); i++)
			{
				os << std::setw(width) << std::fixed << std::setprecision(decimals) << xvalues[i]
					<< std::setw(width) << std::fixed << std::setprecision(decimals) << yvalues[i] << std::endl;
			}

		}
	};
	
	template<typename T>  // For tempate class DataTable !!
	std::ostream& operator<<(std::ostream& fs, const DataTable<T>& d)
	{
		d.display(fs);
		return fs;
	}
	
}

