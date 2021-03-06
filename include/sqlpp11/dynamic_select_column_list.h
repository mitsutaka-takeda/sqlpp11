/*
 * Copyright (c) 2013-2015, Roland Bock
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 *   Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 *   Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef SQLPP_SELECT_COLUMN_LIST_FWD_H
#define SQLPP_SELECT_COLUMN_LIST_FWD_H

#include <vector>
#include <string>
#include <sqlpp11/named_interpretable.h>

namespace sqlpp
{
  template <typename Db>
  struct dynamic_select_column_list
  {
    using _names_t = std::vector<std::string>;
    std::vector<named_interpretable_t<Db>> _dynamic_columns;
    _names_t _dynamic_expression_names;

    template <typename Expr>
    void emplace_back(Expr expr)
    {
      _dynamic_expression_names.push_back(name_of<Expr>::char_ptr());
      _dynamic_columns.emplace_back(expr);
    }

    bool empty() const
    {
      return _dynamic_columns.empty();
    }
  };

  template <>
  struct dynamic_select_column_list<void>
  {
    struct _names_t
    {
      static constexpr size_t size()
      {
        return 0;
      }
    };
    _names_t _dynamic_expression_names;

    static constexpr bool empty()
    {
      return true;
    }
  };
}

#endif
