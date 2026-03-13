/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 20:11:45 by asemykin          #+#    #+#             */
/*   Updated: 2026/03/13 21:52:07 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdint.h>

struct Data
{
    size_t      n;
    int         value;
    std::string text;    
};

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer &copy);
        ~Serializer();
        Serializer &operator=(const Serializer &copy);
    public:
        static uintptr_t serialize(Data *ptr);
        static Data *deserialize(uintptr_t raw);        
};

