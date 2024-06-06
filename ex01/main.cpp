/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:50:47 by jmigoya-          #+#    #+#             */
/*   Updated: 2024/06/06 17:01:38 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>
#include <stdint.h>

int main()
{
    // Create a new Data object on the heap
    Data *dataOriginal = new Data();
    dataOriginal->type = "Hola, mundo!";
    dataOriginal->value = 42;

    // Serialize the Data object
    uintptr_t serializedData = Serializer::serialize(dataOriginal);
    std::cout << "Serialized data is: " << serializedData << std::endl;

    // Deserialize the serialized data
    Data *dataDeserialized = Serializer::deserialize(serializedData);
    std::cout << "Deserialized data is of type: " << dataDeserialized->type 
              << " with value: " << dataDeserialized->value << std::endl;

    // Delete the original Data object to free up memory
    delete dataOriginal;

    return 0;
}
