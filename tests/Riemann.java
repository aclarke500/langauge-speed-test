class Riemann {

    static double leftSideRiemannSums(double a, double b) {
        // we need to define the width of the rectangles
        double width = 0.0001;
        double sum = 0;
        double position = a; // we start at a double a
        double val = 0;

        while (position < b) {
            val = exampleFunction(position);
            val *= width;
            // System.out.println(val);
            sum += val;
            position += width;
        }
        return sum;
    }

    static double exampleFunction(double x) {
        return x * x * x + 4;
    }


    public static void main(String[] args) {
        final long startTime = System.currentTimeMillis();
        double val = leftSideRiemannSums(0, 100);
        final long endTime = System.currentTimeMillis();
        // System.out.println("state");
        double timeInSeconds = (endTime - startTime);

        timeInSeconds = timeInSeconds / 1000;

        System.out.println(timeInSeconds);

    }
}