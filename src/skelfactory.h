/*
 * Copyright (C) 2002 Lorenzo Bettini <http://www.lorenzobettini.it>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */

#ifndef SKELFACTORY_H
#define SKELFACTORY_H

// implementation of pattern "Abstract Factory"

class SkelStruct;
class NormalText;
class VarItem;

#include <string>

#include "skelitemtype.h"
#include "skelitemoptions.h"

using std::string;

class SkelItems;
class StreamStruct;

class SkelFactory
{
 public:
  virtual SkelStruct *createSkelStruct (SkelItems *items,
                                        const string &name,
                                        const string &file_name,
                                        StreamStruct &,
                                        bool sep_files = false) = 0;
  virtual NormalText *createNormalText (const string &);
  virtual VarItem *createVarItem (const string &, const skelitem_type &t = NOTYPE,
                                  SkelItemOptions opts = SkelItemOptions ());

  virtual ~SkelFactory() {}
};

#endif // SKELFACTORY_H
