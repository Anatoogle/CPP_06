/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 22:52:56 by asemykin          #+#    #+#             */
/*   Updated: 2026/03/14 12:08:40 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"
#include "../includes/Base.hpp"

#include <iostream>
#include <cstdlib>

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

int main()
{
    srand(time(0)); // for generating random number
    
    std::cout << "Test 1 -------------------" << std::endl;
    {
        Base *base = generate();
        Base &b = *base;
        
        identify(base);
        identify(b);
        
        delete base; 
    }
    std::cout << "\nTest 2 -------------------" << std::endl;
    {
        Base *base1 = generate();
        Base *base2 = generate();
        Base &b = *base2;
        
        identify(base1);
        identify(base2);
        identify(b);
        
        delete base1;
        delete base2; 
    }
    std::cout << "\nTest 3 -------------------" << std::endl;
    {
        class F:public Base {};
        
        Base *a = new F;
        Base &b = *a;
        
        identify(a);
        identify(b);
        
        delete a; 
    }
    
    return 0;
}

Base *generate(void)
{
    int randomNumber = std::rand() % 3;

    if(randomNumber == 0)
        return new A;
    else if(randomNumber == 1)
        return new B;
    else
        return new C;
}

void identify(Base *p)
{
    if(dynamic_cast<A*>(p))
        std::cout << "Pointer   Datatype is: A" << std::endl;
    else if(dynamic_cast<B*>(p))
        std::cout << "Pointer   Datatype is: B" << std::endl;
    else if(dynamic_cast<C*>(p))
        std::cout << "Pointer   Datatype is: C" << std::endl;
    else
        std::cout << "Datatype is unknown" << std::endl;
}

void identify(Base &p)
{
    try
    {
        dynamic_cast<A&>(p);
        std::cout << "Reference Datatype is: A" << std::endl;
        return;
    }   
    catch(const std::exception &e)
    {}
    try
    {
        dynamic_cast<B&>(p);
        std::cout << "Reference Datatype is: B" << std::endl;
        return;
    }
    catch(const std::exception& e)
    {}
    try
    {
        dynamic_cast<C&>(p);
        std::cout << "Reference Datatype is: C" << std::endl;
        return;
    }
    catch(const std::exception& e)
    {}

    std::cout << "Datatype is unknown" << std::endl;
}
