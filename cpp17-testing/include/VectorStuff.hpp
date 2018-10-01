#pragma once

#include <vector>
#include <functional>

/* this essentially is a std::for_each clone by me to try and help me learn templates
 * when a function is passed in, it's automatically called with the 'it' value, and any other optional args */
template <typename Vector_Type, typename... Args> 
void forInVector(const std::vector<Vector_Type>& vector, std::function<void(Vector_Type, Args...)>& func, Args... args) 
{
	for (const auto& it : vector) func(it, args...); 
}

template <typename Vector_Type>
void forInVector(const std::vector<Vector_Type>& vector, std::function<void(Vector_Type)>& func)
{
    for (const auto& it : vector) func(it);
}

template <typename Vector_Type, typename... Args>
void forInVector(const std::vector<Vector_Type>& vector, void(*func)(Vector_Type, Args...), Args... args)
{
    for (const auto& it : vector) func(it, args...);
}

template <typename Vector_Type>
void forInVector(const std::vector<Vector_Type>& vector, void(*func)(Vector_Type))
{
    for (const auto& it : vector) func(it);
}

/* this is a scrapped lambda implementation that doesn't work for shit */
/* template <typename Vector_Type, typename Lambda_Type, typename... Args>
 * void forInVector(const std::vector<Vector_Type>& vector, Lambda_Type& lambda, Args... args)
 * { for (const auto& it : vector) lambda(it, args...); }
 *
 * template <typename Vector_Type, typename Lambda_Type>
 * void forInVector(const std::vector<Vector_Type>& vector, Lambda_Type& lambda)
 * { for (const auto& it : vector) lambda(it); } */

/* this is a helper function for the raw pointer w/ args overload
 * usage: forInVector(aVector, &copyVector, &aVector_copy) */
template <typename Vector_Type> 
void copyVector(Vector_Type x, std::vector<Vector_Type>* vector) 
{
	vector->push_back(x);
}