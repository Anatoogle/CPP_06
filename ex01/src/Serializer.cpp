/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 20:40:02 by asemykin          #+#    #+#             */
/*   Updated: 2026/03/13 20:56:07 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

uintptr_t Serializer::serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}

