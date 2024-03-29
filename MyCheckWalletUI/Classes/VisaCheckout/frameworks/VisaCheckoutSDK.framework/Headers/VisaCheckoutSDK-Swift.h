// Generated by Apple Swift version 4.1 effective-3.3 (swiftlang-902.0.48 clang-902.0.37.1)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgcc-compat"

#if !defined(__has_include)
# define __has_include(x) 0
#endif
#if !defined(__has_attribute)
# define __has_attribute(x) 0
#endif
#if !defined(__has_feature)
# define __has_feature(x) 0
#endif
#if !defined(__has_warning)
# define __has_warning(x) 0
#endif

#if __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <objc/NSObject.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus)
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...)
# endif
#endif

#if __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if __has_attribute(objc_method_family)
# define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
#else
# define SWIFT_METHOD_FAMILY(X)
#endif
#if __has_attribute(noescape)
# define SWIFT_NOESCAPE __attribute__((noescape))
#else
# define SWIFT_NOESCAPE
#endif
#if __has_attribute(warn_unused_result)
# define SWIFT_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
#else
# define SWIFT_WARN_UNUSED_RESULT
#endif
#if __has_attribute(noreturn)
# define SWIFT_NORETURN __attribute__((noreturn))
#else
# define SWIFT_NORETURN
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM_ATTR)
# if defined(__has_attribute) && __has_attribute(enum_extensibility)
#  define SWIFT_ENUM_ATTR __attribute__((enum_extensibility(open)))
# else
#  define SWIFT_ENUM_ATTR
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name) enum _name : _type _name; enum SWIFT_ENUM_ATTR SWIFT_ENUM_EXTRA _name : _type
# if __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_ATTR SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME) SWIFT_ENUM(_type, _name)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if !defined(SWIFT_UNAVAILABLE_MSG)
# define SWIFT_UNAVAILABLE_MSG(msg) __attribute__((unavailable(msg)))
#endif
#if !defined(SWIFT_AVAILABILITY)
# define SWIFT_AVAILABILITY(plat, ...) __attribute__((availability(plat, __VA_ARGS__)))
#endif
#if !defined(SWIFT_DEPRECATED)
# define SWIFT_DEPRECATED __attribute__((deprecated))
#endif
#if !defined(SWIFT_DEPRECATED_MSG)
# define SWIFT_DEPRECATED_MSG(...) __attribute__((deprecated(__VA_ARGS__)))
#endif
#if __has_feature(attribute_diagnose_if_objc)
# define SWIFT_DEPRECATED_OBJC(Msg) __attribute__((diagnose_if(1, Msg, "warning")))
#else
# define SWIFT_DEPRECATED_OBJC(Msg) SWIFT_DEPRECATED_MSG(Msg)
#endif
#if __has_feature(modules)
@import Foundation;
@import QuartzCore;
@import UIKit;
@import CoreGraphics;
@import ObjectiveC;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
#if __has_warning("-Wpragma-clang-attribute")
# pragma clang diagnostic ignored "-Wpragma-clang-attribute"
#endif
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma clang diagnostic ignored "-Wnullability"

#if __has_attribute(external_source_symbol)
# pragma push_macro("any")
# undef any
# pragma clang attribute push(__attribute__((external_source_symbol(language="Swift", defined_in="VisaCheckoutSDK",generated_declaration))), apply_to=any(function,enum,objc_interface,objc_category,objc_protocol))
# pragma pop_macro("any")
#endif













/// A brand of credit card associated with a payment
typedef SWIFT_ENUM_NAMED(NSInteger, VisaCardBrand, "CardBrand") {
/// American Express
  VisaCardBrandAmex = 0,
/// Discover
  VisaCardBrandDiscover = 1,
/// Electron
  VisaCardBrandElectron = 2,
/// Elo
  VisaCardBrandElo = 3,
/// Mastercard
  VisaCardBrandMastercard = 4,
/// Visa
  VisaCardBrandVisa = 5,
};

@class NSCoder;
@class UIImage;
@class VisaCurrencyAmount;
enum VisaCurrency : NSInteger;
@class VisaCheckoutResult;
@class VisaPurchaseInfo;
enum VisaCheckoutButtonStyle : NSInteger;

/// This is the main point of interaction for your customers. The user
/// will tap this button in order to initiate the Visa Checkout SDK’s
/// user interface. A CheckoutButton can have a <code>CheckoutButtonStyle</code>
/// for different visual rendering options.
/// You can use the <code>onCheckout(total:currency:completion:)</code> methods to provide information that
/// is used when the button is tapped by the user.
/// Alternatively, you may add a target-action mechanism provided by <code>UIControl</code>
/// instances. You may then call the <code>VisaCheckoutSDK.checkout()</code> methods
/// directly to manually launch the Visa Checkout SDK’s user interface.
/// CheckoutButton can only have 2 heights - 34 or 47 points. Setting the height < 34 will
/// result in a height of 34 points. Setting the height > 47 will result in a height of 47.
/// If the height is set somewhere between 34-40, the height will snap down to 34.
/// If the height is set somewhere between 41-47, the height will snap up to 47.
/// CheckoutButton width can be anywhere from 154 to 425. Widths < 154 will snap to 154 and
/// widths > 425 will snap to 425. However, unlike height, the width can be set anywhere
/// between 154-425 and that width will be honored.
/// <hr/>
/// <em>Example setting the purchase information to an instance of CheckoutButton</em>
/// \code
/// checkoutButton.onCheckout(total: 22.09, currency: .usd) { result in
///    print(result.statusCode)
/// }
///
/// \endcode
SWIFT_CLASS_NAMED("CheckoutButton")
@interface VisaCheckoutButton : UIControl
/// :nodoc:
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
/// :nodoc:
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
/// The <code>enableAnimation</code> is used to turn on or off the animation on the button.
@property (nonatomic) BOOL enableAnimation;
/// :nodoc:
@property (nonatomic, getter=isEnabled) BOOL enabled;
/// :nodoc:
- (void)layoutSubviews;
/// <img src="../img/mini.png" alt="miniButtonImage"/>
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, strong) UIImage * _Nonnull miniButtonImage;)
+ (UIImage * _Nonnull)miniButtonImage SWIFT_WARN_UNUSED_RESULT;
/// A convenience method to set the most basic information needed to complete a transaction.
/// The information will be used once the button is tapped by the user. This method may be
/// called multiple times, as needed.
/// \param total The total amount of the purchase your customer is attempting to pay.
///
/// \param currency The <code>Currency</code> used for this purchase amount.
///
/// \param completion A completion handler that is called when the <code>VisaCheckoutSDK</code> is finished and
/// has return context back to your app.
///
- (void)onCheckoutWithTotal:(VisaCurrencyAmount * _Nonnull)total currency:(enum VisaCurrency)currency completion:(void (^ _Nonnull)(VisaCheckoutResult * _Nonnull))completion;
/// A method to set the detailed <code>PurchaseInfo</code> used to complete a transaction.
/// The information will be used once the button is tapped by the user. This method may be
/// called multiple times, as needed.
/// \param purchaseInfo The purchase information with various settings used to customize the Checkout experience.
///
/// \param completion A completion handler that is called when the <code>VisaCheckoutSDK</code> is finished and
/// has return context back to your app.
///
- (void)onCheckoutWithPurchaseInfo:(VisaPurchaseInfo * _Nonnull)purchaseInfo completion:(void (^ _Nonnull)(VisaCheckoutResult * _Nonnull))completion;
/// Convenience property for Interface Builder to set the value of
/// <code>style</code> to <code>CheckoutButtonStyle.standard</code>. Default value is <code>true</code>.
@property (nonatomic) BOOL standardStyle;
/// The <code>CheckoutButtonStyle</code> to use for rendering. This is used to
/// contrast with lighter or darker background superviews.
@property (nonatomic) enum VisaCheckoutButtonStyle style;
@end






@interface VisaCheckoutButton (SWIFT_EXTENSION(VisaCheckoutSDK))
/// :nodoc:
- (CGSize)sizeThatFits:(CGSize)size SWIFT_WARN_UNUSED_RESULT;
/// :nodoc:
@property (nonatomic, readonly) CGSize intrinsicContentSize;
/// :nodoc:
- (void)prepareForInterfaceBuilder;
@end





/// The style to used for rendering a <code>CheckoutButton</code> instance.
typedef SWIFT_ENUM_NAMED(NSInteger, VisaCheckoutButtonStyle, "CheckoutButtonStyle") {
/// <img src="../img/neutral.png" title="Neutral Button" alt="Neutral Button">
  VisaCheckoutButtonStyleNeutral = 0,
/// <img src="../img/standard.png" title="Standard Button" alt="Standard Button">
  VisaCheckoutButtonStyleStandard = 1,
};

/// The result code indicating the status of a completed <code>configure()</code>
/// call of the VisaCheckoutSDK class.
typedef SWIFT_ENUM_NAMED(NSInteger, VisaCheckoutConfigStatus, "CheckoutConfigStatus") {
/// You have attempted to run the Visa Checkout SDK in debug mode
/// while simultaneously configuring using <code>Environment.production</code>
/// as the ’environment` value.
  VisaCheckoutConfigStatusDebugModeNotSupported = 0,
/// An internal error occurred. This is unexpected behavior and should be
/// reported to a Visa Checkout team member.
  VisaCheckoutConfigStatusInternalError = 1,
/// You have supplied an incorrect API Key value for the <code>apiKey</code>
/// property. Be sure to obtain a valid API Key from your developer
/// account and also remember to use the correct API Key for the correct
/// environment.
/// For example, you will have at least 2 API Keys. One
/// for the <code>Environment.sandbox</code> type and one for the <code>Environment.production</code>
/// type. Be sure you are using the correct one and also be sure
/// you have copied the value correctly.
  VisaCheckoutConfigStatusInvalidAPIKey = 2,
/// You have provided an incorrect profileName value. If you wish
/// to use the default profile on your account, you can pass nil.
  VisaCheckoutConfigStatusInvalidProfileName = 3,
/// There was an unexpected network failure. This can either be due
/// to an inconsistent internet connection or from an invalid
/// parameter being used while configuring VisaCheckoutSDK.
  VisaCheckoutConfigStatusNetworkFailure = 4,
/// Visa Checkout does not support landscape-only iPhone apps.
/// The app must also support portrait orientation.
  VisaCheckoutConfigStatusNoCommonSupportedOrientations = 5,
/// You are using an unsupported version of the Visa Checkout SDK.
/// You must upgrade to a newer version in order to use the SDK.
  VisaCheckoutConfigStatusSdkVersionDeprecation = 6,
/// Config is complete with no errors.
  VisaCheckoutConfigStatusSuccess = 7,
};

enum VisaCountry : NSInteger;
enum VisaCheckoutResultStatus : NSInteger;

/// The <code>CheckoutResult</code> class is the object that is returned when a Visa Checkout
/// launch has occurred and finished. This class will contain information
/// related to the user’s payment if successful. If the checkout attempt was
/// unsuccessful, it will contain an error code in <code>statusCode</code>.
SWIFT_CLASS_NAMED("CheckoutResult")
@interface VisaCheckoutResult : NSObject
/// An internal identifier provided by the Visa Checkout SDK.
/// Use this value as the value for the <code>PurchaseInfo.referenceCallId</code>
/// property if you need to make modifications to a successful checkout
/// transaction.
@property (nonatomic, readonly, copy) NSString * _Nullable callId;
/// The brand of the credit card the user has chosen to use for this
/// purchase.
/// This is only populated if <code>statusCode</code> is of type <code>success</code>.
@property (nonatomic) enum VisaCardBrand cardBrand;
/// The country associated with this user.
/// This is only populated if <code>statusCode</code> is of type <code>success</code>.
@property (nonatomic) enum VisaCountry country;
/// The encrypted key that is used to decrypt the <code>encryptedPaymentData</code>.
/// This is only populated if <code>statusCode</code> is of type <code>success</code>.
@property (nonatomic, readonly, copy) NSString * _Nullable encryptedKey;
/// The encrypted payment data containing the card information.
/// This data needs to be decrypted using the <code>encryptedKey</code>.
/// This is only populated if <code>statusCode</code> is of type <code>success</code>.
@property (nonatomic, readonly, copy) NSString * _Nullable encryptedPaymentData;
/// The last four digits of the credit card the user has chosen to
/// use for this purchase.
/// This is only populated if <code>statusCode</code> is of type <code>success</code>.
@property (nonatomic, readonly, copy) NSString * _Nullable lastFourDigits;
/// The payment method type, set to either TOKEN or PAN.
/// This is only populated if <code>statusCode</code> is of type <code>success</code> and merchant has enabled tokenization.
@property (nonatomic, readonly, copy) NSString * _Nullable paymentMethodType;
/// The postal code associated with this user.
/// This is only populated if <code>statusCode</code> is of type <code>success</code>.
@property (nonatomic, readonly, copy) NSString * _Nullable postalCode;
/// The status of this checkout attempt.
@property (nonatomic, readonly) enum VisaCheckoutResultStatus statusCode;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_DEPRECATED_MSG("-init is unavailable");
@end

/// The result code indicating the status of a completed Visa Checkout
/// transaction. This is the code found in the <code>statusCode</code> of the
/// <code>CheckoutResult</code> class.
typedef SWIFT_ENUM_NAMED(NSInteger, VisaCheckoutResultStatus, "CheckoutResultStatus") {
/// Your call to attempt a manual checkout was rejected because the user
/// interface is already being shown to the user.
  VisaCheckoutResultStatusDuplicateCheckoutAttempt = 0,
/// An internal error occurred. This is unexpected behavior and should be
/// reported to a Visa Checkout team member.
  VisaCheckoutResultStatusInternalError = 1,
/// Your call to attempt a manual checkout was rejected because you
/// have not configured <code>VisaCheckoutSDK</code>. You need to make sure you
/// call <code>VisaCheckoutSDK.configure()</code> and the <code>VisaCheckoutSDK.isReady</code>
/// property is <code>true</code>.
  VisaCheckoutResultStatusNotConfigured = 2,
/// This is a successful checkout attempt. If <code>statusCode</code> is
/// <code>success</code>, then all of the other payment information is assumed
/// to be valid.
  VisaCheckoutResultStatusSuccess = 3,
/// The user cancelled the checkout attempt by closing down the user interface.
  VisaCheckoutResultStatusUserCancelled = 4,
};

/// This type represents a country that Visa Checkout supports.
typedef SWIFT_ENUM_NAMED(NSInteger, VisaCountry, "Country") {
/// Argentina
  VisaCountryArgentina = 0,
/// Australia
  VisaCountryAustralia = 1,
/// Brazil
  VisaCountryBrazil = 2,
/// Canada
  VisaCountryCanada = 3,
/// Chile
  VisaCountryChile = 4,
/// China
  VisaCountryChina = 5,
/// Colombia
  VisaCountryColombia = 6,
/// France
  VisaCountryFrance = 7,
/// Hong Kong
  VisaCountryHongKong = 8,
/// India
  VisaCountryIndia = 9,
/// Ireland
  VisaCountryIreland = 10,
/// Malaysia
  VisaCountryMalaysia = 11,
/// Mexico
  VisaCountryMexico = 12,
/// New Zealand
  VisaCountryNewZealand = 13,
/// Peru
  VisaCountryPeru = 14,
/// Poland
  VisaCountryPoland = 15,
/// Singapore
  VisaCountrySingapore = 16,
/// South Africa
  VisaCountrySouthAfrica = 17,
/// Spain
  VisaCountrySpain = 18,
/// United Arab Emirates
  VisaCountryUnitedArabEmirates = 19,
/// United Kingdom
  VisaCountryUnitedKingdom = 20,
/// United States
  VisaCountryUnitedStates = 21,
/// Ukraine
  VisaCountryUkraine = 22,
/// Kuwait
  VisaCountryKuwait = 23,
/// Saudi Arabia
  VisaCountrySaudiArabia = 24,
/// Qatar
  VisaCountryQatar = 25,
};

/// This type represents a currency that Visa Checkout supports.
typedef SWIFT_ENUM_NAMED(NSInteger, VisaCurrency, "Currency") {
/// United Arab Emirates Dirham
  VisaCurrencyAed = 0,
/// Argentina Peso
  VisaCurrencyArs = 1,
/// Australia Dollar
  VisaCurrencyAud = 2,
/// Brazil Real
  VisaCurrencyBrl = 3,
/// Canada Dollar
  VisaCurrencyCad = 4,
/// Chili Peso
  VisaCurrencyClp = 5,
/// China Yuan/Renminbi
  VisaCurrencyCny = 6,
/// Colombia Peso
  VisaCurrencyCop = 7,
/// Euro
  VisaCurrencyEur = 8,
/// Great Britain Pound
  VisaCurrencyGbp = 9,
/// Hong Kong Dollar
  VisaCurrencyHkd = 10,
/// India Rupee
  VisaCurrencyInr = 11,
/// Kuwait Dinar
  VisaCurrencyKwd = 12,
/// Mexico Peso
  VisaCurrencyMxn = 13,
/// Malaysia Ringgit
  VisaCurrencyMyr = 14,
/// New Zealand Dollar
  VisaCurrencyNzd = 15,
/// Peru Nuevo Sol
  VisaCurrencyPen = 16,
/// Poland Zloty
  VisaCurrencyPln = 17,
/// Qatar Riyal
  VisaCurrencyQar = 18,
/// Saudi Arabia Riyal
  VisaCurrencySar = 19,
/// Singapore Dollar
  VisaCurrencySgd = 20,
/// Ukraine hryvnia
  VisaCurrencyUah = 21,
/// USA Dollar
  VisaCurrencyUsd = 22,
/// South Africa Rand
  VisaCurrencyZar = 23,
};

@class NSDecimalNumber;

/// A ‘CurrencyAmount’ encapsulates money values. It can be initialized
/// with String, NSDecimalNumber, Double, and Int types.
SWIFT_CLASS_NAMED("CurrencyAmount")
@interface VisaCurrencyAmount : NSObject
/// :nodoc:
- (nonnull instancetype)initWithIntegerLiteral:(NSInteger)value OBJC_DESIGNATED_INITIALIZER;
/// :nodoc:
- (nonnull instancetype)initWithFloatLiteral:(double)value OBJC_DESIGNATED_INITIALIZER;
/// :nodoc:
- (nonnull instancetype)initWithStringLiteral:(NSString * _Nonnull)value OBJC_DESIGNATED_INITIALIZER;
/// :nodoc:
- (nonnull instancetype)initWithExtendedGraphemeClusterLiteral:(NSString * _Nonnull)value OBJC_DESIGNATED_INITIALIZER;
/// :nodoc:
- (nonnull instancetype)initWithUnicodeScalarLiteral:(NSString * _Nonnull)value OBJC_DESIGNATED_INITIALIZER;
/// :nodoc:
- (nonnull instancetype)initWithDecimalNumber:(NSDecimalNumber * _Nonnull)decimalNumber OBJC_DESIGNATED_INITIALIZER;
/// :nodoc:
- (nonnull instancetype)initWithDouble:(double)double_ OBJC_DESIGNATED_INITIALIZER;
/// :nodoc:
- (nonnull instancetype)initWithInt:(NSInteger)int_ OBJC_DESIGNATED_INITIALIZER;
/// :nodoc:
- (nonnull instancetype)initWithString:(NSString * _Nonnull)string OBJC_DESIGNATED_INITIALIZER;
/// The string representation of the amount.
@property (nonatomic, readonly, copy) NSString * _Nonnull description;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_DEPRECATED_MSG("-init is unavailable");
@end





/// The level of detail Visa Checkout sends back in the <code>CheckoutResult</code> object once the transaction completes.
typedef SWIFT_ENUM_NAMED(NSInteger, VisaDataLevel, "DataLevel") {
/// Includes all of the transaction information
  VisaDataLevelFull = 0,
/// Only the <code>statusCode</code> and <code>callId</code> are returned.
  VisaDataLevelNone = 1,
/// Includes some, but not all of the transaction information.
  VisaDataLevelSummary = 2,
};

/// Environment is the context in which Visa Checkout SDK will connect. For testing
/// and debugging purposes, <code>sandbox</code> should be used. When deploying to the general
/// public, <code>production</code> must be used.
/// Each environment will have a different <code>apiKey</code> associated with it. It is important
/// to remember to change the API Key to the production API Key value before submitting
/// apps to the App Store.
/// note:
/// Visa Checkout SDK does not support debugging with an <code>environment</code> value of
/// <code>production</code>. An error will occur and print to the console reminding you that debug
/// mode is only possible in the <code>sandbox</code> environment.
/// <hr/>
/// <em>An example of automating the <code>apiKey</code> and <code>environment</code> value based on a
/// debug mode flag</em>
/// \code
/// #if MY_DEBUG_FLAG
///    let environment = Environment.sandbox
///    let apiKey = "mySandboxAPIKey_wwoikl2j3lkss-2idh39"
/// #else
///    let environment = Environment.production
///    let apiKey = "myProductionAPIKey_p21p1a9S-28wlj2k1"
/// #endif
///
/// \endcode
typedef SWIFT_ENUM_NAMED(NSInteger, VisaEnvironment, "Environment") {
/// Production is used for deploying your app to the general public for
/// use. This environment will use live Visa Checkout accounts.
/// note:
/// Visa Checkout SDK does not support debugging with an <code>environment</code> value of
/// <code>production</code>. An error will occur and print to the console reminding you that debug
/// mode is only possible in the <code>sandbox</code> environment.
/// You must remember to use a separate <code>apiKey</code> for <code>production</code> than you use
/// for <code>sandbox</code>. It is important to remember to change the API Key to
/// the correct one before publishing your app to the general public.
  VisaEnvironmentProduction = 0,
/// Sandbox is used for debugging and integration testing. Anyone can create
/// Visa Checkout accounts and submit test payments without any effect on
/// real world credit card transactions. There is minimal validation on
/// credit card details and addresses, but otherwise is a simulated production
/// environment.
/// You must remember to use a separate <code>apiKey</code> for <code>sandbox</code> than you use
/// for <code>production</code>. It is important to remember to change the API Key to
/// the correct one before publishing your app to the general public.
  VisaEnvironmentSandbox = 1,
};


























/// The <code>Profile</code> class is the mechanism to customize the Visa Checkout SDK’s
/// configuration. These settings allow various modifications to the way
/// the SDK behaves and also the way it appears to your users.
SWIFT_CLASS_NAMED("Profile")
@interface VisaProfile : NSObject
/// Set false if Canadian debit cards are not accepted.
/// Default is true.
@property (nonatomic) BOOL acceptCanadianDebitCards;
/// The API Key string given associated with your Visa Merchant account.
/// This key will be dependent on which <code>environment</code> you are connecting to. For instance, you
/// will have one API Key for the Sandbox <code>environment</code> and a different API Key for the Production <code>environment</code>.
@property (nonatomic, copy) NSString * _Nonnull apiKey;
/// Apply child directed treatment for Google ad tracking if COPPA compliance is necessary.
/// Default value is <code>false</code>.
@property (nonatomic) BOOL applyChildDirectedTreatmentForGoogleAds;
/// Set the client id if needed
@property (nonatomic, copy) NSString * _Nullable clientId;
/// The level of detail that is return on the <code>CheckoutResult</code>
/// object after the user completes a Visa Checkout transaction.
@property (nonatomic) enum VisaDataLevel datalevel;
/// How Visa Checkout should refer to your company/app
@property (nonatomic, copy) NSString * _Nullable displayName;
/// Set this to true to enabled tokenization.
@property (nonatomic) BOOL enableTokenization;
/// The server environment to use
@property (nonatomic) enum VisaEnvironment environment;
/// If you provide this along with <code>facebookAdvertisingID</code>, we will
/// send Visa Checkout screen visible events to your facebook event tracker on your
/// behalf
@property (nonatomic, copy) NSString * _Nullable facebookAppID;
/// If you provide this along with <code>facebookAppID</code>, we will
/// send Visa Checkout screen visible events to your facebook event tracker on your
/// behalf. This should be the value of Apple’s Advertising Identifier (IDFA).
@property (nonatomic, copy) NSString * _Nullable facebookAdvertisingID;
/// Provide the file name of a custom PNG logo to be
/// shown inside Visa Checkout. The file should be a
/// resource accessible by your app bundle.
@property (nonatomic, copy) NSString * _Nullable logo;
/// Specify the encryption key to be used by Visa
@property (nonatomic, copy) NSString * _Nullable encryptionKey;
/// The profile name associated with your Visa Merchant account. Default is <em>default</em>.
@property (nonatomic, copy) NSString * _Nullable profileName;
/// Initializer with basic information required to configure the
/// Visa Checkout SDK.
/// <ul>
///   <li>
///     Parameters:
///   </li>
///   <li>
///     environment: The <code>environment</code>.
///   </li>
///   <li>
///     apiKey: The <code>apiKey</code>.
///   </li>
///   <li>
///     profileName: The <code>profileName</code>.
///   </li>
/// </ul>
- (nonnull instancetype)initWithEnvironment:(enum VisaEnvironment)environment apiKey:(NSString * _Nonnull)apiKey profileName:(NSString * _Nullable)profileName OBJC_DESIGNATED_INITIALIZER;
- (void)acceptedBillingCountries:(NSArray<NSNumber *> * _Nonnull)countries;
- (void)acceptedCardBrands:(NSArray<NSNumber *> * _Nonnull)brands;
- (void)acceptedShippingCountries:(NSArray<NSNumber *> * _Nonnull)countries;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_DEPRECATED_MSG("-init is unavailable");
@end



enum VisaReviewAction : NSInteger;

/// The <code>PurchaseInfo</code> class is used for you to send the Visa Checkout SDK the
/// detailed information regarding your customers’ purchase. Use this class
/// if you need to pass more detailed information other than the amount and
/// currency.
SWIFT_CLASS_NAMED("PurchaseInfo")
@interface VisaPurchaseInfo : NSObject
/// Add any custom key/value pairs if needed. Keys can be a
/// maximum of 100 characters and values can be maximum of
/// 500 characters.
@property (nonatomic, copy) NSDictionary<NSString *, NSString *> * _Nullable customData;
/// A custom description you may use to describe this purchase. Informational only.
@property (nonatomic, copy) NSString * _Nullable customDescription;
/// The amount of a discount on this purchase. Informational only.
@property (nonatomic, strong) VisaCurrencyAmount * _Nullable discount;
/// The gift wrapping charges associated with this purchase.
/// Informational only.
@property (nonatomic, strong) VisaCurrencyAmount * _Nullable giftWrapCharges;
/// Any amount associated with miscellaneous charges for this purchase.
/// Informational only.
@property (nonatomic, strong) VisaCurrencyAmount * _Nullable miscellaneousCharges;
/// A custom value you may use to identify the purchase. Informational only.
@property (nonatomic, copy) NSString * _Nullable orderId;
/// A promotional code entered by the user to make this purchase.
/// Informational only.
@property (nonatomic, copy) NSString * _Nullable promoCode;
/// This value should be set if a successful <code>CheckoutResult</code> was received
/// AND you need to modify the purchase by invoking the Visa Checkout
/// SDK again for the same purchase.
/// For instance, if the user successfully completes the Visa Checkout process,
/// <code>CheckoutResult.callId</code> will be populated with a string that represents
/// this purchase. If, then, you need to make adjustments to the exact same
/// purchase, you must be sure to set this value to the one obtained from
/// <code>CheckoutResult.callId</code> before the user attempts to checkout again.
/// <hr/>
/// <em>An example of setting the <code>referenceCallId</code> with the value from a
/// <code>CheckoutResult</code> instance</em>
/// \code
/// let checkoutResult: CheckoutResult = ...
/// let purchaseInfo = PurchaseInfo(...)
///
/// purchaseInfo.referenceCallId = checkoutResult.callId
///
/// \endcode
@property (nonatomic, copy) NSString * _Nullable referenceCallId;
/// A custom value you may use to identify this Visa Checkout attempt.
/// Informational only.
@property (nonatomic, copy) NSString * _Nullable requestId;
/// Indicates to the user if there will be another ‘finalize
/// purchase’ screen once returning to your application.
/// Default is <code>continue</code>
@property (nonatomic) enum VisaReviewAction reviewAction;
/// Allows setting a custom review and continue message
/// shown as a label below the Continue/Pay button
@property (nonatomic, copy) NSString * _Nullable reviewMessage;
/// The shipping and handling charges associated with this purchase.
/// Informational only.
@property (nonatomic, strong) VisaCurrencyAmount * _Nullable shippingAndHandlingCharges;
/// Determines whether you require a shipping address from your
/// customers. If <code>true</code>, the user will be required to provide
/// a valid shipping address in addition to a valid billing
/// address. This should be set to <code>true</code> if you intend to send
/// physical items to the user. Default value is <code>false</code>.
@property (nonatomic) BOOL shippingRequired;
/// A custom value you may use to identify this user. Informational only.
@property (nonatomic, copy) NSString * _Nullable sourceId;
/// The subtotal of the purchase. Informational only.
@property (nonatomic, strong) VisaCurrencyAmount * _Nullable subtotal;
/// The taxes assessed on this purchase. Informational only.
@property (nonatomic, strong) VisaCurrencyAmount * _Nullable tax;
/// Set this to true if 3DS should be active.
@property (nonatomic) BOOL threeDSActive;
/// Set this to true if 3DS should not challenge the user.
@property (nonatomic) BOOL threeDSSuppressChallenge;
/// \param total Required to notify the user of the total amount of this purchase.
///
/// \param currency Required to identify which currency the total amount is being
/// charged.
///
- (nonnull instancetype)initWithTotal:(VisaCurrencyAmount * _Nonnull)total currency:(enum VisaCurrency)currency OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_DEPRECATED_MSG("-init is unavailable");
@end



/// Indicates to the user if there will be another ‘finalize purchase’
/// screen once returning to the parent application.
typedef SWIFT_ENUM_NAMED(NSInteger, VisaReviewAction, "ReviewAction") {
/// Communicate to the user that their card information will be transferred to your app
/// and stored somewhere other than their Visa Checkout account.
  VisaReviewActionCardOnFile = 0,
/// Purchase will require another ‘finalize purchase’ screen after Visa Checkout closes
  VisaReviewActionContinue = 1,
/// Purchase will be completed by tapping the ‘pay’ button inside Visa Checkout
  VisaReviewActionPay = 2,
};


























































/// The <code>VisaCheckoutSDK</code> class is the way you will initialize the Visa Checkout SDK.
/// It is required to call <code>VisaCheckoutSDK.configure()</code> so that the Visa Checkout SDK
/// can get setup and enable the <code>CheckoutButton</code> for your customers.
/// It is recommended to call <code>VisaCheckoutSDK.configure()</code> early in the app lifecycle, such as in
/// the <code>didFinishLaunchingWithOptions</code> delegate method. <code>configure()</code> may be called
/// multiple times if needed.
/// <hr/>
/// <em>Example configuring the Visa Checkout SDK</em>
/// \code
/// VisaCheckoutSDK.configure(environment: .sandbox,
///                           apiKey: "<#Your API Key goes here#>")
///
/// \endcode<hr/>
/// You can also use the VisaCheckoutSDK class to manually launch
/// the SDK’s user interface. This may desired if using a custom
/// button for your users to tap. In this case, without the
/// CheckoutButton, you are required to call
/// <code>VisaCheckoutSDK.checkout()</code> directly.
/// <hr/>
/// <em>Example calling checkout() to launch Visa Checkout SDK manually</em>
/// \code
/// VisaCheckoutSDK.checkout(total: 22.09, currency: .usd) { result in
///     print(result.statusCode)
/// }
///
/// \endcode
SWIFT_CLASS_NAMED("VisaCheckoutSDK")
@interface VisaCheckoutSDK : NSObject
/// A method to manually launch the Visa Checkout user interface with the detailed
/// <code>PurchaseInfo</code> used to complete a transaction. If the Visa Checkout SDK is configured
/// properly, this will immediately present the Visa Checkout user interface to the user.
/// \param purchaseInfo The purchase information with various settings used to customize the Checkout experience.
///
/// \param completion A completion handler that is called when the <code>VisaCheckoutSDK</code> is finished and
/// has return context back to your app.
///
+ (void)checkoutWithPurchaseInfo:(VisaPurchaseInfo * _Nonnull)purchaseInfo completion:(void (^ _Nonnull)(VisaCheckoutResult * _Nonnull))completion;
/// A convenience method to manually launch the Visa Checkout user interface with the basic
/// information needed to complete a transaction. If the Visa Checkout SDK is configured
/// properly, this will immediately present the Visa Checkout user interface to the user.
/// \param total The total amount of the purchase your customer is attempting to pay.
///
/// \param currency The <code>Currency</code> used for this purchase amount.
///
/// \param completion A completion handler that is called when the <code>VisaCheckoutSDK</code> is finished and
/// has return context back to your app.
///
+ (void)checkoutWithTotal:(VisaCurrencyAmount * _Nonnull)total currency:(enum VisaCurrency)currency completion:(void (^ _Nonnull)(VisaCheckoutResult * _Nonnull))completion;
/// Call this method to configure the Visa Checkout SDK using the basic information
/// required to launch the Visa Checkout user interface.
/// \param environment The context with which Visa Checkout accounts are managed. For instance,
/// <code>sandbox</code> will not have actual Visa Checkout accounts and it is safe to use this environment
/// for testing the Visa Checkout integration.
///
/// \param apiKey The API Key string given associated with your Visa Merchant account.
/// This key will be dependent on which <code>environment</code> you are connecting to. For instance, you
/// will have one API Key for the Sandbox <code>environment</code> and a different API Key for the Production <code>environment</code>.
///
/// \param profileName The profile name associated with your Visa Merchant account.
///
/// \param result The result of configuring the Visa Checkout SDK. This result will report
/// any errors if there were issues initializing. It will also report a successful configuration,
/// at which time the <code>CheckoutButton</code> will be ready to interact with.
///
+ (void)configureWithEnvironment:(enum VisaEnvironment)environment apiKey:(NSString * _Nonnull)apiKey profileName:(NSString * _Nullable)profileName result:(void (^ _Nullable)(enum VisaCheckoutConfigStatus))result;
/// Call this method to configure the Visa Checkout SDK using a <code>Profile</code> object with customizable
/// options.
/// \param profile The profile object that holds all of your profile customizations options.
///
/// \param result The result of configuring the Visa Checkout SDK. This result will report
/// any errors if there were issues initializing. It will also report a successful configuration,
/// at which time the <code>CheckoutButton</code> will be ready to interact with.
///
+ (void)configureWithProfile:(VisaProfile * _Nonnull)profile result:(void (^ _Nullable)(enum VisaCheckoutConfigStatus))result;
/// A value indicating whether the Visa Checkout SDK is configured and ready to launch,
/// whether launched manually or through a <code>CheckoutButton</code> tap. The <code>CheckoutButton</code> will be
/// enabled when this property is <code>true</code> (and disabled when this property is <code>false</code>).
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly) BOOL isReady;)
+ (BOOL)isReady SWIFT_WARN_UNUSED_RESULT;
/// Use for campaign tracking promotions.
/// Should be set in the application(_:open:options:) UIApplicationDelegate method.
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, copy) NSURL * _Nullable marketingUrl;)
+ (NSURL * _Nullable)marketingUrl SWIFT_WARN_UNUSED_RESULT;
+ (void)setMarketingUrl:(NSURL * _Nullable)newValue;
/// Call this method to update payment information after original information passed to Visa has changed.
/// \param parameters A dictionary of key/value pairs that should include
/// apiKey, callId, eventType, some amount key e.g. ‘total’, and currencyCode.
///
+ (void)updatePaymentInfoWithParameters:(NSDictionary<NSString *, id> * _Nonnull)parameters;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end



#if __has_attribute(external_source_symbol)
# pragma clang attribute pop
#endif
#pragma clang diagnostic pop
