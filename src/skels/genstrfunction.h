/*
 * File automatically generated by
 * gengen 1.0 by Lorenzo Bettini 
 * http://www.gnu.org/software/gengen
 */

#ifndef GENSTRFUNCTION_GEN_CLASS_H
#define GENSTRFUNCTION_GEN_CLASS_H

#include <string>
#include <iostream>

using std::string;
using std::ostream;

class genstrfunction_gen_class
{
 protected:
  string assignfields;
  string genname;
  string genparameters;
  string strgeninstructions;
  string structname;

 public:
  genstrfunction_gen_class()
  {
  }
  
  genstrfunction_gen_class(const string &_assignfields, const string &_genname, const string &_genparameters, const string &_strgeninstructions, const string &_structname) :
    assignfields (_assignfields), genname (_genname), genparameters (_genparameters), strgeninstructions (_strgeninstructions), structname (_structname)
  {
  }

  virtual ~genstrfunction_gen_class()
  {
  }

  static void
  generate_string(const string &s, ostream &stream, unsigned int indent)
  {
    if (!indent || s.find('\n') == string::npos)
      {
        stream << s;
        return;
      }

    string::size_type pos;
    string::size_type start = 0;
    string ind (indent, ' ');
    while ( (pos=s.find('\n', start)) != string::npos)
      {
        stream << s.substr (start, (pos+1)-start);
        start = pos+1;
        if (start+1 <= s.size ())
          stream << ind;
      }
    if (start+1 <= s.size ())
      stream << s.substr (start);
  }

  virtual void generate_assignfields(ostream &stream, unsigned int indent) = 0;

  void set_assignfields(const string &_assignfields)
  {
    assignfields = _assignfields;
  }

  void set_genname(const string &_genname)
  {
    genname = _genname;
  }

  virtual void generate_genparameters(ostream &stream, unsigned int indent) = 0;

  void set_genparameters(const string &_genparameters)
  {
    genparameters = _genparameters;
  }

  virtual void generate_strgeninstructions(ostream &stream, unsigned int indent) = 0;

  void set_strgeninstructions(const string &_strgeninstructions)
  {
    strgeninstructions = _strgeninstructions;
  }

  void set_structname(const string &_structname)
  {
    structname = _structname;
  }

  void generate_genstrfunction(ostream &stream, unsigned int indent = 0)
  {
    string indent_str (indent, ' ');
    indent = 0;
  
    stream << "\n";
    stream << indent_str;
    stream << "char *";
    stream << "\n";
    stream << indent_str;
    stream << "genstring_";
    generate_string (genname, stream, indent + indent_str.length ());
    stream << "(struct ";
    generate_string (structname, stream, indent + indent_str.length ());
    stream << " *record, unsigned int indent)";
    stream << "\n";
    stream << indent_str;
    stream << "{";
    stream << "\n";
    stream << indent_str;
    stream << "  char *indent_str, *output;";
    stream << "\n";
    stream << indent_str;
    stream << "  unsigned int i;";
    stream << "\n";
    stream << indent_str;
    stream << "  int len;";
    stream << "\n";
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
    stream << "  indent_str = (char *) malloc (indent + 1);";
    stream << "\n";
    stream << indent_str;
    stream << "  for (i = 0; i < indent; ++i)";
    stream << "\n";
    stream << indent_str;
    stream << "    indent_str[i] = ' ';";
    stream << "\n";
    stream << indent_str;
    stream << "  indent_str[indent] = '\\0';";
    stream << "\n";
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
    stream << "  len = strcnt_";
    generate_string (genname, stream, indent + indent_str.length ());
    stream << " (record, indent);";
    stream << "\n";
    stream << indent_str;
    stream << "  output = (char *) malloc (len + 1);";
    stream << "\n";
    stream << indent_str;
    stream << "  output[0] = '\\0';";
    stream << "\n";
    stream << indent_str;
    indent = 2;
    if (strgeninstructions.size () > 0)
      generate_string (strgeninstructions, stream, indent + indent_str.length ());
    else
      generate_strgeninstructions (stream, indent + indent_str.length ());
    indent = 0;
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
    stream << "  free (indent_str);";
    stream << "\n";
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
    stream << "  return output;";
    stream << "\n";
    stream << indent_str;
    stream << "}";
    stream << "\n";
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
    stream << "char *";
    stream << "\n";
    stream << indent_str;
    stream << "genstringp_";
    generate_string (genname, stream, indent + indent_str.length ());
    stream << "(unsigned int indent";
    if (genparameters.size () > 0)
      generate_string (genparameters, stream, indent + indent_str.length ());
    else
      generate_genparameters (stream, indent + indent_str.length ());
    stream << ")";
    stream << "\n";
    stream << indent_str;
    stream << "{";
    stream << "\n";
    stream << indent_str;
    stream << "  struct ";
    generate_string (structname, stream, indent + indent_str.length ());
    stream << " record;";
    stream << "\n";
    stream << indent_str;
    indent = 2;
    stream << "  ";
    if (assignfields.size () > 0)
      generate_string (assignfields, stream, indent + indent_str.length ());
    else
      generate_assignfields (stream, indent + indent_str.length ());
    indent = 0;
    stream << "\n";
    stream << indent_str;
    stream << "  return genstring_";
    generate_string (genname, stream, indent + indent_str.length ());
    stream << " (&record, indent);";
    stream << "\n";
    stream << indent_str;
    stream << "}";
    stream << "\n";
    stream << indent_str;
  }
};

#endif // GENSTRFUNCTION_GEN_CLASS_H
