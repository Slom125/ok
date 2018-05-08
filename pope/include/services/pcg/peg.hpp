/*
  This file is part of Pope.

  Copyright (c) 2018 by Breno Viana

  Pope is a free software; you can redistribute it and/or modify it under the
  terms of the MIT License.
*/

#ifndef _POPE_PEG_HPP_
#define _POPE_PEG_HPP_

class WorkPass;

#include <iostream>
#include <list>
#include <vector>
#include <random>
#include <yaml-cpp/yaml.h>
#include "domain/entrant.hpp"
#include "domain/papers/paper.hpp"
#include "domain/papers/date.hpp"
#include "domain/papers/picture.hpp"

#define MALE 'M'
#define FEMALE 'F'

/*!
 * \brief This class is responsible for procedural entrant generation (PEG)
 */
class PEG {
  public:
    /*!
     * \brief
     *
     * \param database
     *     Database
     */
    static std::list<Entrant*> generate(YAML::Node database);
  private:
    /*!
     * \brief
     *
     * \param database
     *     Database
     */
    static Entrant* new_entrant(YAML::Node database);

    /*!
     * \brief
     *
     * \param database
     *     Database
     */
    static Passport* new_passport(YAML::Node database, Entrant* entrant,
      bool illegal, int& illegal_fields);

    /*!
     * \brief
     *
     * \param database
     *     Database
     */
    static IDCard* new_idcard(YAML::Node database, Entrant* entrant,
      bool illegal, int& illegal_fields);

    /*!
     * \brief
     *
     * \param database
     *     Database
     */
    static AccessPermit* new_accesspermit(YAML::Node database, Entrant* entrant,
      Passport* passport, bool illegal, int& illegal_fields);

    /*!
     * \brief
     *
     * \param database
     *     Database
     */
    static WorkPass* new_workpass(YAML::Node database, Entrant* entrant,
      AccessPermit* accesspermit, bool illegal, int& illegal_fields);
};

typedef std::uniform_int_distribution<std::mt19937::result_type> RandomInt;

#endif /* _POPE_PEG_HPP_ */