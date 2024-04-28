/*
 * utilities.h
 *
 * Created: 3/30/2024 1:52:07 PM
 *  Author: Abdelrahman
 */ 


#ifndef UTILITIES_H_
#define UTILITIES_H_

#define SET_BIT(REG,POS)	(REG |= (1<<POS))
#define CLEAR_BIT(REG,POS)	(REG &= ~(1<<POS))
#define TOGGLE_BIT(REG,POS)	(REG ^= (1<<POS))
#define READ_BIT(REG,POS)	(REG &= (1<<POS))

#endif /* UTILITIES_H_ */