#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <map>

class Harl
{
    private:
        static const size_t fn_count = 4;
        std::string         messages_str[fn_count];
        void                (Harl::*messages_fn[fn_count])(void);
        void                debug(void);
        void                info(void);
        void                warning(void);
        void                error(void);
    public:
        Harl();
        void    complain(std::string level);
};

#endif