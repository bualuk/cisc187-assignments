#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include <doctest.h>
#include <lab19.h>

SCENARIO( "Test Dog class") {
  
  WHEN( "a default Dog is created" ) {
    Dog d;
    THEN( "the default name == 'Fido'" ) {
      REQUIRE (d.name() == "Fido");
    }
    THEN( "the default Size == 'Size::MEDIUM'" ) {
      REQUIRE (d.size() == Size::MEDIUM);
    }
  }

  WHEN( "a LARGE Dog is created with name 'Max'" ) {
    Dog d {"Max", Size::LARGE};
    THEN( "the name == 'Max'" ) {
      REQUIRE (d.name() == "Max");
    }
    THEN( "the Size == 'Size::LARGE'" ) {
      REQUIRE (d.size() == Size::LARGE);
    }
  }

  WHEN( "a SMALL Dog is created with name 'Princess'" ) {
    Dog d {"Princess", Size::SMALL};
    THEN( "the name == 'Princess'" ) {
      REQUIRE (d.name() == "Princess");
    }
    THEN( "the Size == 'Size::SMALL'" ) {
      REQUIRE (d.size() == Size::SMALL);
    }
  }

  WHEN( "a Dog is created with name 'Princess'" ) {
    Dog d {"Princess", Size::SMALL};
    THEN( "the name == 'Princess'" ) {
      REQUIRE (d.name() == "Princess");
    }
    d.name("Fluffy");
    AND_WHEN( "the the name is changed to 'Fluffy'" ) {
      THEN( "the name should now equal 'Fluffy'" ) {
        REQUIRE (d.name() == "Fluffy");
      }
    }
  }
  WHEN( "a LARGE Dog is created" ) {
    Dog d {"Cujo", Size::LARGE};
    THEN( "bark should return 'Woof'" ) {
      REQUIRE (d.bark() == "Woof");
    }
  }

  WHEN( "a Medium Dog is created" ) {
    Dog d {"Balto", Size::MEDIUM};
    THEN( "bark should return 'Ruff'" ) {
      REQUIRE (d.bark() == "Ruff");
    }
  }

  WHEN( "a Small Dog is created" ) {
    Dog d {"Benji", Size::SMALL};
    THEN( "bark should return 'Yip'" ) {
      REQUIRE (d.bark() == "Yip");
    }
  }


}


