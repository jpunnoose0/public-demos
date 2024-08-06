# ImageMath Example

## Summary

This tutorial will show you some basic examples on how to use our ImageMath plugin.
The plugin offers compile-time optimized arithmetic expressions for our image types and has optimizes code paths for both, GPU and CPU execution.
In this example we will convert a color image to gray and apply a mask based on intensity values.

![Screenshot of the plugin in action](screenshot.png)

**Note:** This demo plugin is build upon the ExamplePlugin. Please refer to the README.md there for more details on setting up an ImFusionPlugin.

## Implementation details

- We use the `Configurable` interface and a `Parameter` to configure the weighting used in the conversion to gray. The `DefaultAlgorithmController` will automatically create a UI for this parameter.
- The conversion to gray is done by a simple weighted sum of the color channels.
- As the mask is depending on the intensity values, we need to define a variable in our expression which later gets substituted by the intensity values of the image.
