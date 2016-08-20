
#ifndef OBJECT_H
#define OBJECT_H
class Object{
      protected:
            virtual int compareTo( Object const &) const = 0;
      public:
            virtual ~Object(void);
            virtual bool isNull(void) const;
            virtual int compare(Object const &) const;
            virtual void print(std::ostream& = std::cout) const = 0;
};

class NullObject : public Object{
      protected:
            NullObject(void);
      public:
            bool isNull(void) const;
            virtual void print(std::ostream& = std::cout) const;
};

#endif
