import numpy as np
import matplotlib.pyplot as plt
import scipy as sp

def main():
    # Define parameters
    num_samples = 1024
    sample_rate = 20000

    t = np.arange(num_samples) / sample_rate

    # Generate sine waves
    freq_1kHz = 1000  # 1 kHz frequency
    freq_5kHz = 5000  # 5 kHz frequency

    sine_wave_1kHz = .5 * np.sin(2 * np.pi * freq_1kHz * t)
    sine_wave_5kHz = .1 * np.sin(2 * np.pi * freq_5kHz * t)

    # Combine the sine waves
    combined_wave = sine_wave_1kHz + sine_wave_5kHz

    # Y axis
    fft = sp.fft.fft(combined_wave)
    # X axis
    freq = sp.fft.fftfreq(num_samples, 1/sample_rate)
    
    coef = create_lpf_coefficients(29, .25)
    filtered_signal = lp_filter(combined_wave, coef)
    
    filtered_fft = sp.fft.fft(filtered_signal)

    # Create figure
    fig, ((ax1, ax2), (ax3, ax4)) = plt.subplots(2, 2)
    fig.suptitle('FFT Simulation')

    # Sim data plot
    ax1.plot(t, combined_wave)
    ax1.set_title('Sim Data')
    ax1.set_ylabel('Amplitude')
    ax1.set_xlabel('Time')

    # FFT plot
    ax2.plot(np.abs(freq), np.abs(fft))
    ax2.set_title('FFT')
    ax2.set_xlabel('Frequency')
    ax2.set_ylabel('Amplitude')
    
    # Filtered signal plot
    ax3.plot(t, filtered_signal)
    ax3.set_title('Filtered Signal')
    ax3.set_ylabel('Amplitude')
    ax3.set_xlabel('Time')
    
    # Filtered FFT plot
    ax4.plot(np.abs(freq), np.abs(filtered_fft))
    ax4.set_title('Filtered FFT')
    ax4.set_xlabel('Frequency')
    ax4.set_ylabel('Amplitude')

    plt.show()


def print_c_array(array):
    for i in range(array.size):
        print(f"    {array[i]},")
    print("};")
    
def create_lpf_coefficients(numtaps, cutoff):
    return sp.signal.firwin(numtaps, cutoff, window='hamming', pass_zero='lowpass')

def lp_filter(data, coef):
    return sp.signal.lfilter(coef, 1, data)

if __name__ == "__main__":
    main()