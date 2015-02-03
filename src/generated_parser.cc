// A Bison parser, made by GNU Bison 3.0.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2013 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Take the name prefix into account.
#define yylex   clidoclex

// First part of user declarations.

#line 39 "generated_parser.cc" // lalr1.cc:399

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "generated_parser.h"

// User implementation prologue.

#line 53 "generated_parser.cc" // lalr1.cc:407
// Unqualified %code blocks.
#line 27 "flex-bison-scripts/parser.y" // lalr1.cc:408


#include <stdexcept>

#include "src/generated_scanner.h"

#undef yylex
#define yylex lexer_ptr->lex

// Error report function.
void clidoc::BisonGeneratedParser::error(const std::string &msg) {
  throw std::logic_error("clidoc::BisonGeneratedParser::error");
}


#line 71 "generated_parser.cc" // lalr1.cc:408


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif



// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyempty = true)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace clidoc {
#line 138 "generated_parser.cc" // lalr1.cc:474

  /// Build a parser object.
  BisonGeneratedParser::BisonGeneratedParser (clidoc::FlexGeneratedScanner *lexer_ptr_yyarg, clidoc::Doc::SharedPtr *doc_node_ptr_yyarg, clidoc::OptionBindingRecorder *recorder_ptr_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      lexer_ptr (lexer_ptr_yyarg),
      doc_node_ptr (doc_node_ptr_yyarg),
      recorder_ptr (recorder_ptr_yyarg)
  {}

  BisonGeneratedParser::~BisonGeneratedParser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  inline
  BisonGeneratedParser::by_state::by_state ()
    : state (empty)
  {}

  inline
  BisonGeneratedParser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  BisonGeneratedParser::by_state::move (by_state& that)
  {
    state = that.state;
    that.state = empty;
  }

  inline
  BisonGeneratedParser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  BisonGeneratedParser::symbol_number_type
  BisonGeneratedParser::by_state::type_get () const
  {
    return state == empty ? 0 : yystos_[state];
  }

  inline
  BisonGeneratedParser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  BisonGeneratedParser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s)
  {
      switch (that.type_get ())
    {
      case 22: // testcases
      case 23: // single_testcase
      case 24: // body
      case 25: // compound
      case 26: // list
      case 27: // elements
      case 28: // dict
      case 29: // pairs
      case 30: // single_pair
      case 31: // single_element
      case 32: // boolean
      case 33: // number
      case 34: // string
        value.move< WeakPtr > (that.value);
        break;

      case 3: // K_BEGIN
      case 4: // K_END
      case 5: // K_INPUT
      case 6: // K_OUTPUT
      case 7: // K_BOOLEAN_TRUE
      case 8: // K_BOOLEAN_FALSE
      case 9: // K_EQUAL_SIGN
      case 10: // K_COMMA
      case 11: // K_COLON
      case 12: // K_L_BRACKET
      case 13: // K_R_BRACKET
      case 14: // K_L_BRACE
      case 15: // K_R_BRACE
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty;
  }

  inline
  BisonGeneratedParser::stack_symbol_type&
  BisonGeneratedParser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 22: // testcases
      case 23: // single_testcase
      case 24: // body
      case 25: // compound
      case 26: // list
      case 27: // elements
      case 28: // dict
      case 29: // pairs
      case 30: // single_pair
      case 31: // single_element
      case 32: // boolean
      case 33: // number
      case 34: // string
        value.copy< WeakPtr > (that.value);
        break;

      case 3: // K_BEGIN
      case 4: // K_END
      case 5: // K_INPUT
      case 6: // K_OUTPUT
      case 7: // K_BOOLEAN_TRUE
      case 8: // K_BOOLEAN_FALSE
      case 9: // K_EQUAL_SIGN
      case 10: // K_COMMA
      case 11: // K_COLON
      case 12: // K_L_BRACKET
      case 13: // K_R_BRACKET
      case 14: // K_L_BRACE
      case 15: // K_R_BRACE
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }


  template <typename Base>
  inline
  void
  BisonGeneratedParser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  BisonGeneratedParser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  BisonGeneratedParser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  BisonGeneratedParser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  BisonGeneratedParser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  BisonGeneratedParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  BisonGeneratedParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  BisonGeneratedParser::debug_level_type
  BisonGeneratedParser::debug_level () const
  {
    return yydebug_;
  }

  void
  BisonGeneratedParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline BisonGeneratedParser::state_type
  BisonGeneratedParser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  BisonGeneratedParser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  BisonGeneratedParser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  BisonGeneratedParser::parse ()
  {
    /// Whether yyla contains a lookahead.
    bool yyempty = true;

    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyempty)
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
        yyempty = false;
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Discard the token being shifted.
    yyempty = true;

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      case 22: // testcases
      case 23: // single_testcase
      case 24: // body
      case 25: // compound
      case 26: // list
      case 27: // elements
      case 28: // dict
      case 29: // pairs
      case 30: // single_pair
      case 31: // single_element
      case 32: // boolean
      case 33: // number
      case 34: // string
        yylhs.value.build< WeakPtr > ();
        break;

      case 3: // K_BEGIN
      case 4: // K_END
      case 5: // K_INPUT
      case 6: // K_OUTPUT
      case 7: // K_BOOLEAN_TRUE
      case 8: // K_BOOLEAN_FALSE
      case 9: // K_EQUAL_SIGN
      case 10: // K_COMMA
      case 11: // K_COLON
      case 12: // K_L_BRACKET
      case 13: // K_R_BRACKET
      case 14: // K_L_BRACE
      case 15: // K_R_BRACE
        yylhs.value.build< std::string > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 94 "flex-bison-scripts/parser.y" // lalr1.cc:847
    {
}
#line 557 "generated_parser.cc" // lalr1.cc:847
    break;

  case 3:
#line 96 "flex-bison-scripts/parser.y" // lalr1.cc:847
    {
}
#line 564 "generated_parser.cc" // lalr1.cc:847
    break;

  case 4:
#line 100 "flex-bison-scripts/parser.y" // lalr1.cc:847
    {
}
#line 571 "generated_parser.cc" // lalr1.cc:847
    break;

  case 5:
#line 104 "flex-bison-scripts/parser.y" // lalr1.cc:847
    {
}
#line 578 "generated_parser.cc" // lalr1.cc:847
    break;

  case 6:
#line 110 "flex-bison-scripts/parser.y" // lalr1.cc:847
    {
}
#line 585 "generated_parser.cc" // lalr1.cc:847
    break;

  case 7:
#line 112 "flex-bison-scripts/parser.y" // lalr1.cc:847
    {
}
#line 592 "generated_parser.cc" // lalr1.cc:847
    break;

  case 8:
#line 114 "flex-bison-scripts/parser.y" // lalr1.cc:847
    {
}
#line 599 "generated_parser.cc" // lalr1.cc:847
    break;

  case 9:
#line 118 "flex-bison-scripts/parser.y" // lalr1.cc:847
    {
}
#line 606 "generated_parser.cc" // lalr1.cc:847
    break;

  case 10:
#line 124 "flex-bison-scripts/parser.y" // lalr1.cc:847
    {
}
#line 613 "generated_parser.cc" // lalr1.cc:847
    break;

  case 11:
#line 126 "flex-bison-scripts/parser.y" // lalr1.cc:847
    {
}
#line 620 "generated_parser.cc" // lalr1.cc:847
    break;

  case 12:
#line 128 "flex-bison-scripts/parser.y" // lalr1.cc:847
    {
}
#line 627 "generated_parser.cc" // lalr1.cc:847
    break;

  case 13:
#line 132 "flex-bison-scripts/parser.y" // lalr1.cc:847
    {
}
#line 634 "generated_parser.cc" // lalr1.cc:847
    break;

  case 14:
#line 138 "flex-bison-scripts/parser.y" // lalr1.cc:847
    {
}
#line 641 "generated_parser.cc" // lalr1.cc:847
    break;

  case 15:
#line 140 "flex-bison-scripts/parser.y" // lalr1.cc:847
    {
}
#line 648 "generated_parser.cc" // lalr1.cc:847
    break;

  case 16:
#line 142 "flex-bison-scripts/parser.y" // lalr1.cc:847
    {
}
#line 655 "generated_parser.cc" // lalr1.cc:847
    break;

  case 17:
#line 146 "flex-bison-scripts/parser.y" // lalr1.cc:847
    {
}
#line 662 "generated_parser.cc" // lalr1.cc:847
    break;

  case 18:
#line 152 "flex-bison-scripts/parser.y" // lalr1.cc:847
    {
}
#line 669 "generated_parser.cc" // lalr1.cc:847
    break;

  case 19:
#line 154 "flex-bison-scripts/parser.y" // lalr1.cc:847
    {
}
#line 676 "generated_parser.cc" // lalr1.cc:847
    break;

  case 20:
#line 156 "flex-bison-scripts/parser.y" // lalr1.cc:847
    {
}
#line 683 "generated_parser.cc" // lalr1.cc:847
    break;

  case 21:
#line 161 "flex-bison-scripts/parser.y" // lalr1.cc:847
    {
}
#line 690 "generated_parser.cc" // lalr1.cc:847
    break;

  case 22:
#line 163 "flex-bison-scripts/parser.y" // lalr1.cc:847
    {
}
#line 697 "generated_parser.cc" // lalr1.cc:847
    break;

  case 23:
#line 168 "flex-bison-scripts/parser.y" // lalr1.cc:847
    {
}
#line 704 "generated_parser.cc" // lalr1.cc:847
    break;

  case 24:
#line 170 "flex-bison-scripts/parser.y" // lalr1.cc:847
    {
}
#line 711 "generated_parser.cc" // lalr1.cc:847
    break;

  case 25:
#line 175 "flex-bison-scripts/parser.y" // lalr1.cc:847
    {
}
#line 718 "generated_parser.cc" // lalr1.cc:847
    break;

  case 26:
#line 177 "flex-bison-scripts/parser.y" // lalr1.cc:847
    {
}
#line 725 "generated_parser.cc" // lalr1.cc:847
    break;


#line 729 "generated_parser.cc" // lalr1.cc:847
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yysyntax_error_ (yystack_[0].state,
                                           yyempty ? yyempty_ : yyla.type_get ()));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyempty)
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyempty = true;
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyempty)
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyempty)
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  BisonGeneratedParser::error (const syntax_error& yyexc)
  {
    error (yyexc.what());
  }

  // Generate an error message.
  std::string
  BisonGeneratedParser::yysyntax_error_ (state_type, symbol_number_type) const
  {
    return YY_("syntax error");
  }


  const signed char BisonGeneratedParser::yypact_ninf_ = -14;

  const signed char BisonGeneratedParser::yytable_ninf_ = -1;

  const signed char
  BisonGeneratedParser::yypact_[] =
  {
       1,   -10,     5,   -14,     6,   -14,   -14,    10,    14,    -5,
     -14,   -14,   -14,     9,     9,   -14,   -14,   -14,   -14,     4,
     -14,   -14,   -14,   -14,   -14,   -14,     8,    15,    16,    20,
      13,    23,   -14,     9,   -14,     9,     9,    -5,   -14,   -14,
     -14,   -14
  };

  const unsigned char
  BisonGeneratedParser::yydefact_[] =
  {
       0,     0,     0,     3,     0,     1,     2,     0,     0,     0,
       4,    21,    22,     0,     0,    25,    26,    23,    24,     0,
       7,     8,     6,    18,    19,    20,     0,    12,     0,    16,
       0,     0,     9,    11,    13,    15,     0,     0,    10,    14,
      17,     5
  };

  const signed char
  BisonGeneratedParser::yypgoto_[] =
  {
     -14,   -14,    31,   -14,    -3,   -14,     2,   -14,     3,   -14,
     -13,   -14,   -14,   -14
  };

  const signed char
  BisonGeneratedParser::yydefgoto_[] =
  {
      -1,     2,     3,     8,    19,    20,    26,    21,    28,    29,
      22,    23,    24,    25
  };

  const unsigned char
  BisonGeneratedParser::yytable_[] =
  {
      27,    30,    11,    12,     1,     5,     4,    13,     1,    14,
      31,     7,    15,    16,    17,    18,    11,    12,    10,     9,
      27,    32,    30,    40,    36,    33,    15,    16,    17,    18,
      35,    34,    37,     6,    41,    38,     0,     0,    39
  };

  const signed char
  BisonGeneratedParser::yycheck_[] =
  {
      13,    14,     7,     8,     3,     0,    16,    12,     3,    14,
       6,     5,    17,    18,    19,    20,     7,     8,     4,     9,
      33,    13,    35,    36,    11,    10,    17,    18,    19,    20,
      10,    15,     9,     2,    37,    33,    -1,    -1,    35
  };

  const unsigned char
  BisonGeneratedParser::yystos_[] =
  {
       0,     3,    22,    23,    16,     0,    23,     5,    24,     9,
       4,     7,     8,    12,    14,    17,    18,    19,    20,    25,
      26,    28,    31,    32,    33,    34,    27,    31,    29,    30,
      31,     6,    13,    10,    15,    10,    11,     9,    27,    29,
      31,    25
  };

  const unsigned char
  BisonGeneratedParser::yyr1_[] =
  {
       0,    21,    22,    22,    23,    24,    25,    25,    25,    26,
      27,    27,    27,    28,    29,    29,    29,    30,    31,    31,
      31,    32,    32,    33,    33,    34,    34
  };

  const unsigned char
  BisonGeneratedParser::yyr2_[] =
  {
       0,     2,     2,     1,     4,     6,     1,     1,     1,     3,
       3,     2,     1,     3,     3,     2,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const BisonGeneratedParser::yytname_[] =
  {
  "$end", "error", "$undefined", "K_BEGIN", "K_END", "K_INPUT",
  "K_OUTPUT", "K_BOOLEAN_TRUE", "K_BOOLEAN_FALSE", "K_EQUAL_SIGN",
  "K_COMMA", "K_COLON", "K_L_BRACKET", "K_R_BRACKET", "K_L_BRACE",
  "K_R_BRACE", "ID", "SHORT_STRING", "LONG_STRING", "DECIMAL_INTEGER",
  "FLOAT_NUMBER", "$accept", "testcases", "single_testcase", "body",
  "compound", "list", "elements", "dict", "pairs", "single_pair",
  "single_element", "boolean", "number", "string", YY_NULLPTR
  };


  const unsigned char
  BisonGeneratedParser::yyrline_[] =
  {
       0,    94,    94,    96,   100,   104,   110,   112,   114,   118,
     124,   126,   128,   132,   138,   140,   142,   146,   152,   154,
     156,   161,   163,   168,   170,   175,   177
  };

  // Print the state stack on the debug stream.
  void
  BisonGeneratedParser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  BisonGeneratedParser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG



} // clidoc
#line 1030 "generated_parser.cc" // lalr1.cc:1155
#line 180 "flex-bison-scripts/parser.y" // lalr1.cc:1156

