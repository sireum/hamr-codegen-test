// GUMBO library functions that must not get an assume_specification although a
// same-named function of their own library would qualify, and a result name that must
// avoid every parameter name (GumboRustPlugin.LibraryBodyScan / libraryExecSpecs).
package Foreign {
  language "GUMBO" /*{
    library
      functions
        // arithmetic: machine and mathematical integers disagree at i32::MAX
        def f(x: Base_Types::Integer_32): Base_Types::Boolean := x + 1[s32] > x;
  }*/
}
package Local {
  language "GUMBO" /*{
    library
      functions
        // qualifies: no arithmetic, no call
        def f(x: Base_Types::Integer_32): Base_Types::Boolean := true;
        // calls Foreign's f, not Local's: must not qualify
        def callForeign(x: Base_Types::Integer_32): Base_Types::Boolean := Foreign::GUMBO__Library::f(x);
        // calls Local's own f: qualifies
        def callLocal(x: Base_Types::Integer_32): Base_Types::Boolean := f(x);
        // parameters named res and res_: the result must be named neither
        def resultNames(res: Base_Types::Integer_32, res_: Base_Types::Integer_32): Base_Types::Boolean := true;
  }*/
}
