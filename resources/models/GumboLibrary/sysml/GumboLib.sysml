package GumboLib {
    language "GUMBO" /*{
        library
            functions
                def normalLibraryFunction(a: Gubmo_Structs_Arrays::MyArrayInt32): Base_Types::Boolean :=
                    librarySpecFunction_Guarantee(a) &

                    (0 .. size(a) - 2) -> forAll {i; a#(i) <= a#(i + 1)};
                    

                // for testing a call to a library spec function from an assume context
                @spec def librarySpecFunction_Assume(a: Gubmo_Structs_Arrays::MyArrayInt32): Base_Types::Boolean;
                
                
                // for testing a call to a library spec function from a guarantee context
                @spec def librarySpecFunction_Guarantee(a: Gubmo_Structs_Arrays::MyArrayInt32): Base_Types::Boolean;                
    }*/
}