import numpy as np
import matplotlib.pyplot as plt
import scipy as sp

def main():
    ################################################################
    # Define input file paths here
    
    real_signal_path ='real_signal_out.txt'
    real_signal_data = read_data(real_signal_path)
    
    fft_input_path = 'unfilt_fft_mag_out.txt'
    fft_input_data = read_data(fft_input_path)
    
    filter_input_path = 'filter_out.txt'
    filter_input_data = read_data(filter_input_path)
    
    fft_filter_input_path = 'filt_fft_mag_out.txt'
    fft_filter_input_data = read_data(fft_filter_input_path)
    
    ################################################################
    
    # Define parameters
    num_samples = 1024
    sample_rate = 20000

    # Create time axis
    t = np.arange(num_samples) / sample_rate

    # Generate sine waves
    freq_1kHz = 1000  # 1 kHz frequency
    freq_5kHz = 5000  # 5 kHz frequency

    # Generate sine waves
    sine_wave_1kHz = np.sin(2 * np.pi * freq_1kHz * t)
    sine_wave_5kHz = .5 * np.sin(2 * np.pi * freq_5kHz * t)

    # Combine the sine waves
    combined_wave = sine_wave_1kHz + sine_wave_5kHz

    # Y axis
    fft = sp.fft.fft(combined_wave)
    
    # X axis
    freq = sp.fft.fftfreq(num_samples, 1/sample_rate)
    half_freq = sp.fft.fftfreq((int)(num_samples/2), 2/sample_rate)
    
    # Create coeefficients for filter
    coef = create_lpf_coefficients(32, .25)
    
    # Filter the signal
    filtered_signal = lp_filter(combined_wave, coef)
    
    # FFT of the filtered signal
    filtered_fft = sp.fft.fft(filtered_signal)

    # Create figures
    fig, ((ax1, ax2), (ax3, ax4)) = plt.subplots(2, 2)
    fig.suptitle('Simulation')
    
    fig2, ((ax5, ax6), (ax7, ax8)) = plt.subplots(2, 2)
    fig2.suptitle('On-Chip Data')

    ################################################################
    
    # Sim data plot
    ax1.plot(t, combined_wave)
    ax1.set_title('Sim Signal')
    ax1.set_ylabel('Amplitude')
    ax1.set_xlabel('Time')

    # Sim FFT plot
    ax2.plot(np.abs(freq), np.abs(fft))
    ax2.set_title('FFT')
    ax2.set_xlabel('Frequency')
    ax2.set_ylabel('Amplitude')
    
    # Sim Filtered signal plot
    ax3.plot(t, filtered_signal)
    ax3.set_title('Filtered Signal')
    ax3.set_ylabel('Amplitude')
    ax3.set_xlabel('Time')
    
    # Sim Filtered FFT plot
    ax4.plot(np.abs(freq), np.abs(filtered_fft))
    ax4.set_title('Filtered FFT')
    ax4.set_xlabel('Frequency')
    ax4.set_ylabel('Amplitude')
    
    ################################################################
    
    # On Chip Signal plot
    ax5.plot(t, real_signal_data)
    ax5.set_title('Real Signal')
    ax5.set_ylabel('Amplitude')
    ax5.set_xlabel('Time')
    
    # On Chip FFT plot
    ax6.plot(np.abs(half_freq), fft_input_data)
    ax6.set_title('FFT')
    ax6.set_xlabel('Frequency')
    ax6.set_ylabel('Amplitude')
    
    # On Chip Filtered plot
    ax7.plot(t, filter_input_data)
    ax7.set_title('Filtered Signal')
    ax7.set_xlabel('Time')
    ax7.set_ylabel('Amplitude')
    
    # On Chip Filtered FFT plot
    ax8.plot(np.abs(half_freq), fft_filter_input_data)
    ax8.set_title('Filtered FFT')
    ax8.set_xlabel('Frequency')
    ax8.set_ylabel('Amplitude')
    
    ################################################################

    plt.show()
    
    # Use these functions to generate test input data and the coefficients for the LPF
    # print_c_array(combined_wave)
    # print_c_array(coef)

# Prints out the array in a format that is easy to copy and paste into a C file
def print_c_array(array):
    for i in range(array.size):
        print("{0:1.8f}f".format(np.float32(array[i])), end=', ')
        if i % 8 == 7:
            print()

# Creates the coefficients for the LPF
def create_lpf_coefficients(numtaps, cutoff):
    return sp.signal.firwin(numtaps, cutoff, window='hamming', pass_zero='lowpass')

# Creates a LPF filter for the simulation
def lp_filter(data, coef):
    return sp.signal.lfilter(coef, 1, data)

# This function exists so that you can copy data out of e2 studio memory view,
# paste it into a text editor, delete the memory address column, and then read it here.
def read_data(file_path):
    # Read all lines from the file
    with open(file_path, 'r') as file:
        lines = file.readlines()

    # Flatten the 2D list into a 1D list of values
    flat_values = [float(value) for line in lines for value in line.split()]

    # Convert the list to a NumPy array
    return (np.array(flat_values))

if __name__ == "__main__":
    main()