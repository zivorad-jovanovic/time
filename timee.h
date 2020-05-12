/**
 * @file timee.h
 * @brief Biblioteka za vremenske funkcije
 * @author Zivorad Jovanovic
 * @date 12-05-2020
 *
 */

#ifndef TIMEE_H_
#define TIMEE_H_

/**
 * Funkcija za inicijalizaciju i konfiguraciju registara
 */
void initTime();

/**
 * Funkcija koja racuna proteklo sistemsko vreme u milisekundama
 * @return Protekli broj milisekundi
 */
unsigned long millis();

/**
 * Funkcija koja generise vremensko kasnjenje
 * @param delay Zeljena vrednost kasnjenja
 */
void delay(unsigned long d);


#endif /* TIMEE_H_ */
