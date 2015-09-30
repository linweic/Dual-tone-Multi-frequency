# Dual-tone-Multi-frequency
ESE519 Lab2 Code implementation
Objective: Use output compare interrupt and pulse width modulation(PWM) to generate different frequency waveforms through HCS12 microcontroller

Part 1
  
  The code generates a required frequency of waveform. The speaker in our circuit will paly sound according to the frequency.

Part 2
  
  Part 2 lets users custimize a waveform regarding frequency and total time. Users input value of the frequency and period of time they want the wavefrom to last through IDE terminal. Code parse the input and make the speaker buzz in similar to part 1.
  
Part 3
  
  In part 3 a key pad is added in the circuit. The goal of this part is to print corresponding characters to the termal per keys being pressed.

Part 4
  
  Instead of printing characters to the screen when keys are pressed, part 4 assign different frequencies to each rows and columns of the key. Whenever a key is pressed, our first stage circuit would generate two waveforms with frequencies equal to the key's row and column frequencies respectively. Then the second stage of our circuit integrates these two signals to generate dual-tone sine waves

Part 5
  
  Part1-4 use output compare interupts to achieve the dual-tone-multi-frequency waveforms. In part 5 the code uses Pulse Width Modulation (PWM) registers in HCS12 to achieve the same goal as of part 4.
  
