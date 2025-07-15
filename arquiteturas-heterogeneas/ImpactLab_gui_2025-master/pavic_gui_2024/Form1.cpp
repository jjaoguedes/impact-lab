#include "Form1.h"
#include <thread> // Necessário para multithreading
#include <System.Drawing.Imaging.h>

using namespace SepiaFilterApp;

void ApplySepiaFilter(int startX, int startY, int endX, int endY, Bitmap^ inputImage, Bitmap^ outputImage)
{
    for (int y = startY; y < endY; y++) {
        for (int x = startX; x < endX; x++) {
            // Get pixel color
            Color pixelColor = inputImage->GetPixel(x, y);

            // Apply the sepia filter formula
            int tr = (int)(0.393 * pixelColor.R + 0.769 * pixelColor.G + 0.189 * pixelColor.B);
            int tg = (int)(0.349 * pixelColor.R + 0.686 * pixelColor.G + 0.168 * pixelColor.B);
            int tb = (int)(0.272 * pixelColor.R + 0.534 * pixelColor.G + 0.131 * pixelColor.B);

            // Ensure the values are within bounds (0 to 255)
            tr = Math::Min(255, tr);
            tg = Math::Min(255, tg);
            tb = Math::Min(255, tb);

            // Set the new pixel color
            outputImage->SetPixel(x, y, Color::FromArgb(tr, tg, tb));
        }
    }
}

System::Void Form1::bt_filter_Sepia_MultiThread_Click(System::Object^ sender, System::EventArgs^ e) {
    // Get the input image
    Bitmap^ inputImage = (Bitmap^)pbox_input->Image;

    // Create a new output image with the same dimensions
    Bitmap^ outputImage = gcnew Bitmap(inputImage->Width, inputImage->Height);

    // Define the middle of the image to divide into two parts for threading
    int midY = inputImage->Height / 2;

    // Create two threads, one for the upper half and one for the lower half of the image
    std::thread t1([=]() {
        ApplySepiaFilter(0, 0, inputImage->Width, midY, inputImage, outputImage);
    });

    std::thread t2([=]() {
        ApplySepiaFilter(0, midY, inputImage->Width, inputImage->Height, inputImage, outputImage);
    });

    // Wait for both threads to finish
    t1.join();
    t2.join();

    // Display the output image
    pbox_output->Image = outputImage;
}
