%  Bio-ExG: Multi-biosignal Amplifier System Design - 01
# 필요한 package들을 import한다.
import numpy as np
import scipy.signal as signal
import matplotlib.pyplot as plt

# 개별 소자의 값을 변수로 선언한다.
C14 = 47e-6
C12 = 47e-9
R15 = 1e3
R13 = 1e6
Coeff1 = C12/C14
Coeff2 = R15/R13

# 필터의 전달함수(Transfer Function)의 계수(Coefficient)를 설정한다. 
num = np.array([1.0, 0])
den = np.array([Coeff1 * Coeff2, Coeff1+ Coeff2, 1])

H = signal.TransferFunction(num, den)
print ('H(s) =', H)

# Frequencies
w_start = 0.1
w_stop = 100e3
step = 10
N = int ((w_stop-w_start )/step) + 1
w = np.linspace (w_start , w_stop , N)
# Bode Plot
w, mag, phase = signal.bode(H, w)
plt.figure()
plt.subplot (2, 1, 1)
plt.semilogx(w, mag) # Bode Magnitude Plot
plt.title("Bode Plot")
plt.grid(visible=None, which='major', axis='both')
plt.grid(visible=None, which='minor', axis='both')
plt.ylabel("Magnitude (dB)")

plt.subplot (2, 1, 2)
plt.semilogx(w, phase) # Bode Phase plot
plt.grid(visible=None, which='major', axis='both')
plt.grid(visible=None, which='minor', axis='both')
plt.ylabel("Phase (deg)")
plt.xlabel("Frequency (rad/sec)")
plt.show()
