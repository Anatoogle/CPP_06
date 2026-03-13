/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 22:52:56 by asemykin          #+#    #+#             */
/*   Updated: 2026/03/13 21:53:57 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

int main()
{
    Data testData;
    testData.n = 0;
    testData.value = 42;
    testData.text = "My Name";

    Data *originalPtr = &testData;
        
    uintptr_t raw = Serializer::serialize(originalPtr);
    std::cout   << "original pointer -> serialized pointer\n"
                << originalPtr << " -> " << raw << "\n" << std::endl;
    
    Data *deserializedPtr = Serializer::deserialize(raw);
    
    if(originalPtr == deserializedPtr)
    {
        std::cout   << "serialized pointer -> deserialized pointer\n"
                    << raw << " -> " << deserializedPtr 
                    << "\n-> original pointer matches deserialized pointer\n" << std::endl;
    }
    else
        std::cout << "!!!something went wrong!!!\n" << std::endl;
        
    std::cout   << "checking deserialized Data:\n"
                << "\t" << deserializedPtr->n << "\n"
                << "\t" << deserializedPtr->value << "\n"
                << "\t" << deserializedPtr->text << std::endl;
    return 0;
}
